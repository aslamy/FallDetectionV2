
#include "ECG2000HzLead3Capture.h"
#include "ECG2000HzLead2Capture.h"
#include "ECG2000HzLead1Capture.h"
#include "ECG1000HzLead3Capture.h"
#include "ECG1000HzLead2Capture.h"
#include "ECG1000HzLead1Capture.h"
#include "TestTone150SinWave250HzLead3Capture.h"
#include "TestTone150SinWave250HzLead2Capture.h"
#include "TestTone150SinWave250HzLead1Capture.h"
#include "GPRSConnection.h"
#include "WiFiConnection.h"
#include "NetworkConnection.h"
#include "MQTTServer.h"
#include "MotionCapture.h"
#include "TestTone250HzCapture.h"
#include "SharedPreferences.h"
#include "LinkitOneFlashFileReader.h"
#include "HashMap.h"
#include "ECGCaptureFactory.h"
#include "DataCapture.h"
#include "SPIdev.h"
#include "ECG.h"
#include "ECGCapture.h"
#include "ADAS1000.h"
#include <Arduino.h>
#include <Wire.h>
#include "LinkedList.h"
#include "ArduinoJson.h"
#include <PubSubClient.h>

#include <LBT.h> 
#include <LBTServer.h>

#define  FILE_NAME "settings.txt"
unsigned int  PACKET_SIZE = 200 ;

ADAS1000 *adas;

ECGCapture* ecgCapture;

MotionCapture * bodyMotion;
GPRSConnection *gprs;
WiFiConnection *wifi;

SharedPreferences *sharedPreferences;
MQTTServer *server;

LinkitOneFlashFileReader *flashReader;

String streamingMode;

void incomingCommand(char* topic, byte* payload, unsigned int length)
{
	Serial.print("Recived message on Topic:");
	Serial.print(topic);
	Serial.print("    Message:");
	String incomingMessage;
	for (int i = 0; i < length; i++)
	{
		incomingMessage += (char)payload[i];
	}
	Serial.println(incomingMessage);

}


void setup()
{

	Serial.begin(9600);
	LBTServer.begin((uint8_t*)"My_BTServer");
	initialize();
}

void freeMemory(void)
{
	delete adas;
	delete ecgCapture;
	delete bodyMotion;
	delete gprs;
	delete wifi;
	delete sharedPreferences;
	delete server;
	delete flashReader;
	
}


void initialize(void)
{
	flashReader = new LinkitOneFlashFileReader(FILE_NAME);
	sharedPreferences = new SharedPreferences(FILE_NAME);

	String mode = sharedPreferences->getString("ECG_MODE", "ECG");
	String rate = sharedPreferences->getString("ECG_RATE", "250Hz");
	String lead = sharedPreferences->getString("ECG_LEAD", "Lead1");

	String wifiAuthentication = sharedPreferences->getString("WIFI_AUTHENTICATION", "");
	String wifiAccessPoint = sharedPreferences->getString("WIFI_ACCESS_POINT", "");
	String wifiPassword = sharedPreferences->getString("WIFI_PASSWORD", "");

	String gprsApn = sharedPreferences->getString("GPRS_APN", "");
	String gprsUsername = sharedPreferences->getString("GPRS_USERNAME", "");
	String gprsPassword = sharedPreferences->getString("GPRS_PASSWORD", "");

	String mqttHost = sharedPreferences->getString("MQTT_HOST", "");
	String mqttPort = sharedPreferences->getString("MQTT_PORT", "1883");
	String mqttPublishChannel = sharedPreferences->getString("MQTT_PUBLISH_CHANNEL", "linkitone-data");
	String mqttSubsctibeChannel = sharedPreferences->getString("MQTT_SUBSCRIBE_CHANNEL", "linkitone-command");
	streamingMode = sharedPreferences->getString("STREAM_MODE", "Bluetooth");

	ecgCapture = ECGCaptureFactory::createECGCapture(mode, rate, lead);
	ecgCapture->initialize();

	wifi = new WiFiConnection(wifiAuthentication, wifiAccessPoint, wifiPassword);

	gprs = new GPRSConnection(gprsApn, gprsUsername, gprsPassword);

	server = new MQTTServer(mqttHost, mqttPort, mqttPublishChannel, mqttSubsctibeChannel);
	server->addNetworkConnection(wifi);
	server->addNetworkConnection(gprs);
	server->setCallback(incomingCommand);

	bodyMotion = new MotionCapture();
	bodyMotion->initialize();


	adas = new ADAS1000();
	Serial.iprintf("ADAS1000_CMREFCTL %x\n", adas->getRegisterValue(ADAS1000_CMREFCTL));
	Serial.iprintf("ADAS1000_FILTCTL %x\n", adas->getRegisterValue(ADAS1000_FILTCTL));
	Serial.iprintf("ADAS1000_ECGCTL %x\n", adas->getRegisterValue(ADAS1000_ECGCTL));
	Serial.iprintf("ADAS1000_FRMCTL %x\n", adas->getRegisterValue(ADAS1000_FRMCTL));
	Serial.iprintf("ADAS1000_TESTTONE %x\n", adas->getRegisterValue(ADAS1000_TESTTONE));
	
}

void bluetoothCommands(String text)
{
	if (text.equalsIgnoreCase("READ_SETTINGS"))
	{
		String settings = flashReader->read();
		LBTServer.write(settings.c_str());
		Serial.println("READ");
	}
	else
	{
		DynamicJsonBuffer jsonBuffer;
		JsonObject& root = jsonBuffer.parseObject(text);
		if (root.success())
		{
			String json;
			root.prettyPrintTo(json);
			flashReader->write(json);
			freeMemory();
			initialize();
			Serial.println("WRITE 1");
		}
	}
}

unsigned long packet = 0;

void loop()
{



	if (LBTServer.connected())
	{

		if (LBTServer.available())
		{
	
			String text = LBTServer.readString();
			bluetoothCommands(text);
			
		}
		
	}
	else
	{
		Serial.println("not connected!");
		LBTServer.accept(1);
	}


	String ecg;
	String acceleration;


	for (int i = 0; i<PACKET_SIZE; i++)
	{
		
		ecg += String(ecgCapture->read(), 6);
		acceleration += String(bodyMotion->getAccelerationSVM(), 2);
		
		if (i < PACKET_SIZE - 1)
		{
			acceleration += ",";
			ecg += ",";
		}
		
	}

	String sendData = "{\"packet\":";
	sendData += packet++;
	//sendData += ",\"position\":{\"latitude\":";
	//sendData += String(1.2, 6);
	//sendData += ",\"longitude\":";
	//sendData += String(1.2, 6);
	//sendData += "},\"ecg\":\[";
	sendData += ",\"ecg\":[";
	sendData += ecg;
	sendData += "]";
	sendData += ",\"acceleration\":[";
	sendData += acceleration;
	sendData += "]}";

	if (streamingMode.equalsIgnoreCase("Bluetooth"))
	{
		if (LBTServer.connected())
		{
			if (!LBTServer.available()){
				LBTServer.write(sendData.c_str());

			}
		}

	}
	else if (streamingMode.equalsIgnoreCase("Server"))
	{
		

	}



	//Serial.println(server->isConnected());
	/*
	DynamicJsonBuffer jsonBuffer;
	JsonObject& root = jsonBuffer.createObject();
	root["packet"] = packet++;
	JsonArray& ecgData = root.createNestedArray("ecg");
	JsonArray& accelerationData = root.createNestedArray("acceleration");
	

	String sendData ;

	for(int i= 0; i<500;i++)
	{
		 ecgData.add(ecgCapture->read(),6);
		// if(i%4==0)
		 {
			// accelerationData.add(bodyMotion->getAccelerationSVM(), 2);
		 }

	}
	root.printTo(sendData);
	if (LBTServer.connected())
	{
		if (!LBTServer.available()){
			//unsigned long start = micros();
			LBTServer.write(sendData.c_str());
			//unsigned long stopp = micros();
			//Serial.println(stopp - start);
			//delay(5000);
		}
		

	}
	

	*/
	//root.printTo(sendData);
	//server->send(sendData);



}


