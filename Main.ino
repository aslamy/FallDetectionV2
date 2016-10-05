#include "GPSConnection.h"
#include "GPRSConnection.h"
#include "WiFiConnection.h"
#include "MQTTServer.h"
#include "MotionCapture.h"
#include "SharedPreferences.h"
#include "LinkitOneFlashFileReader.h"
#include "ECGCaptureFactory.h"
#include "ECGCapture.h"
#include <Arduino.h>
#include <Wire.h>
#include "LinkedList.h"
#include "ArduinoJson.h"
#include <PubSubClient.h>
#include <LBT.h> 
#include <LBTServer.h>
#include <WString.h>
#define  FILE_NAME "settings.txt"

unsigned int LED1 = 7;
unsigned int BLUETOOTH_PACKET_SIZE = 200;
unsigned int MQTT_SERVER_PACKET_SIZE = 1000;
unsigned int sequence = 0;


ECGCapture* ecgCapture;
MotionCapture* bodyMotion;
GPRSConnection* gprs;
WiFiConnection* wifi;
GPSConnection* gps;
SharedPreferences* sharedPreferences;
MQTTServer* server;
LinkitOneFlashFileReader* flashReader;
String streamingMode;

void setup();
void loop();
void initialize(void);
String readJsonData(int size);
void bluetoothCommands(String text);
void serverCommands(char* topic, byte* payload, unsigned int length);
boolean rebootDevice(void* userdata);
void freeMemory(void);


void setup()
{
	Serial.begin(9600);
	initialize();
}

void loop()
{
	if (streamingMode.equalsIgnoreCase("Bluetooth"))
	{
		if (LBTServer.connected())
		{
			digitalWrite(LED1, HIGH);
			if (LBTServer.available())
			{
				String text = LBTServer.readString();
				bluetoothCommands(text);
			}
			else
			{
				String json = readJsonData(BLUETOOTH_PACKET_SIZE);
				LBTServer.write(json.c_str());
			}
		}
		else
		{
			digitalWrite(LED1, LOW);
			LBTServer.accept(1000);
		}
	}
	else if (streamingMode.equalsIgnoreCase("Server"))
	{
		
		if (server->isConnected())
		{
			digitalWrite(LED1, HIGH);
			String json = readJsonData(MQTT_SERVER_PACKET_SIZE);
			server->send(json);
		}
		else
		{
			digitalWrite(LED1, LOW);
		}

	}
}

String readJsonData(int size)
{
	String ecg;
	String acceleration;

	for (int i = 0; i < size; i++)
	{
		ecg += String(ecgCapture->read(), 6);
		acceleration += String(bodyMotion->getAccelerationSVM(), 2);
		if (i < size - 1)
		{
			acceleration += ",";
			ecg += ",";
		}
	}

	String sendData = "{\"sequence\":";
	sendData += sequence++;
	if (streamingMode.equalsIgnoreCase("Server"))
	{
		float latitude;
		float longitude;
		gps->getPosition(&latitude, &longitude);
		sendData += ",\"position\":{\"latitude\":";
		sendData += String(latitude, 6);
		sendData += ",\"longitude\":";
		sendData += String(longitude, 6) + "}";
	}
	sendData += ",\"ecg\":[";
	sendData += ecg;
	sendData += "]";
	sendData += ",\"acceleration\":[";
	sendData += acceleration;
	sendData += "]}\n";
	return sendData;
}

void initialize(void)
{
	pinMode(LED1, OUTPUT);
	digitalWrite(LED1, LOW);
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

	gps = new GPSConnection();

	server = new MQTTServer(mqttHost, mqttPort, mqttPublishChannel, mqttSubsctibeChannel);
	server->addNetworkConnection(wifi);
	server->addNetworkConnection(gprs);
	server->setCallback(serverCommands);

	bodyMotion = new MotionCapture();
	bodyMotion->initialize();

	if (streamingMode.equalsIgnoreCase("Bluetooth"))
	{
		LBTServer.begin((uint8_t*)"LinkItOne_BT");
	}
	else
	{
		wifi->connect();
		gprs->connect();
		gps->powerOn();
	}



	ADAS1000 *adas = new ADAS1000();
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
		String settings = "SETTINGS" + flashReader->read();
		LBTServer.write(settings.c_str());
		delay(2000);
	}
	else if (text.startsWith("SAVE_SETTINGS"))
	{
		text.replace("SAVE_SETTINGS", "");
		DynamicJsonBuffer jsonBuffer;
		JsonObject& root = jsonBuffer.parseObject(text);
		if (root.success())
		{
			String json;
			root.prettyPrintTo(json);
			flashReader->write(json);
			freeMemory();
			initialize();
		}
	}
}


void serverCommands(char* topic, byte* payload, unsigned int length)
{
	String message;
	for (int i = 0; i < length; i++)
	{
		message += (char)payload[i];
	}
	if (message.equalsIgnoreCase("\"command_read_settings\""))
	{
		String settingsJson = "{\"settings\":";
		settingsJson += flashReader->read();
		settingsJson += "}";
		server->send(settingsJson);
	}
	else
	{
		DynamicJsonBuffer jsonBuffer;
		JsonObject& root = jsonBuffer.parseObject(message);
		if (root.success())
		{
			String prettyJson;
			root.prettyPrintTo(prettyJson);
			flashReader->write(prettyJson);
			LTask.remoteCall(rebootDevice, NULL);
		}
	}
}

boolean rebootDevice(void* userdata)
{
	vm_reboot_normal_start();
	return true;
}

void freeMemory(void)
{
	delete ecgCapture;
	delete bodyMotion;
	delete gprs;
	delete wifi;
	delete sharedPreferences;
	delete server;
	delete flashReader;
}
