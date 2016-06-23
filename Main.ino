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
void setup()
{


	Serial.begin(9600);


	delay(3000);

	

	SharedPreferences *shared = SharedPreferences::getInstance();
	String mode = shared->getString("ADAS1000_MODE", "ECG");
	String rate = shared->getString("ADAS1000_DATA_RATE", "250Hz");
	String lead = shared->getString("ADAS1000_LEAD", "Lead1");

	gprs = new GPRSConnection("4G.tele2.se","","");
	wifi = new WiFiConnection("WPA","BENJAMIN","sina3944");

	server = new MQTTServer("iot.eclipse.org", "1883", "linkitone-data", "linkitone-command");
	server->addNetworkConnection(wifi);
	server->addNetworkConnection(gprs);

	ecgCapture = ECGCaptureFactory::createECGCapture(mode,rate,lead);
	ecgCapture->initialize();

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

	server->send("Hello");
	delay(1000);
}
