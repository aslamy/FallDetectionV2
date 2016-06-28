
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


ADAS1000 *adas;

ECGCapture* ecgCapture;

MotionCapture * bodyMotion;
GPRSConnection *gprs;
WiFiConnection *wifi;

MQTTServer *server;

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


	delay(3000);


	SharedPreferences *shared = SharedPreferences::getInstance();

	String mode = shared->getString("ADAS1000_MODE", "ECG");
	String rate = shared->getString("ADAS1000_DATA_RATE", "250Hz");
	String lead = shared->getString("ADAS1000_LEAD", "Lead1");

	String wifiAuthentication = shared->getString("WIFI_AUTHENTICATION", "");
	String wifiAccessPoint = shared->getString("WIFI_ACCESS_POINT", "");
	String wifiPassword = shared->getString("WIFI_PASSWORD", "");

	String gprsApn = shared->getString("GPRS_APN", "");
	String gprsUsername = shared->getString("GPRS_USERNAME", "");
	String gprsPassword = shared->getString("GPRS_PASSWORD", "");

	String mqttHost = shared->getString("MQTT_HOST", "");
	String mqttPort = shared->getString("MQTT_PORT", "1883");
	String mqttPublishChannel = shared->getString("MQTT_PUBLISH_CHANNEL", "linkitone-data");
	String mqttSubsctibeChannel = shared->getString("MQTT_SUBSCRIBE_CHANNEL", "linkitone-command");

	ecgCapture = ECGCaptureFactory::createECGCapture(mode, rate, lead);
	ecgCapture->initialize();

	wifi = new WiFiConnection(wifiAuthentication, wifiAccessPoint, wifiPassword);

	gprs = new GPRSConnection(gprsApn,gprsUsername,gprsPassword);
	
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
int i = 0;

void loop()
{
	Serial.println(server->isConnected());

	DynamicJsonBuffer jsonBuffer;
	JsonObject& root = jsonBuffer.createObject();
	JsonArray& ecgData = root.createNestedArray("ecg");
	JsonArray& accelerationData = root.createNestedArray("acceleration");

	String sendData;

	for(int i= 0; i<1000;i++)
	{
		 ecgData.add(ecgCapture->read(),6);
		 if(i%4==0)
		 {
			 accelerationData.add(bodyMotion->getAccelerationSVM(), 2);
		 }

	}
	root.printTo(sendData);
	server->send(sendData);
}


