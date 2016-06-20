
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

ADAS1000 *adas;

ECGCapture *c;
void setup()
{
	/* add setup code here */

	Serial.begin(9600);

	delay(3000);

	

	c = ECGCaptureFactory::createECGCapture();
	c->initialize();
	
	


	adas = new ADAS1000();
	Serial.iprintf("ADAS1000_CMREFCTL %x\n", adas->getRegisterValue(ADAS1000_CMREFCTL));
	Serial.iprintf("ADAS1000_FILTCTL %x\n", adas->getRegisterValue(ADAS1000_FILTCTL));
	Serial.iprintf("ADAS1000_ECGCTL %x\n", adas->getRegisterValue(ADAS1000_ECGCTL));
	Serial.iprintf("ADAS1000_FRMCTL %x\n", adas->getRegisterValue(ADAS1000_FRMCTL));
}
int i = 0;

void loop()
{
	LinkedList<float> list = c->read(1000);
	Serial.println(list.size());

/*	for(int i = 0;i<list.size();i++)
	{
		Serial.println(list.get(i));
	}
	*/
	//delete list;
}
