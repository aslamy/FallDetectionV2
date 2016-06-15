#include "TestTone150SinWave250HzCapture.h"
#include "ECGCaptureFactory.h"
#include "ECG2000HzCapture.h"
#include "ECG1000HzCapture.h"
#include "ECG500HzCapture.h"
#include "ECG250HzCapture.h"
#include "TestToneCapture.h"
#include "DataCapture.h"
#include "SPIdev.h"
#include "ECG.h"
#include "ECGCapture.h"
#include "ADAS1000.h"
#include <Arduino.h>
#include <Wire.h>

ADAS1000 *adas1000;

ECGCapture *d;

void setup()
{
	/* add setup code here */

	Serial.begin(9600);
	d = ECGCaptureFactory::createECGCapture();
	


	adas1000 = new ADAS1000();

/*	adas1000->setRegisterValue(ADAS1000_CMREFCTL, 0x00000B);
	adas1000->setRegisterValue(ADAS1000_TESTTONE, 0xF8001D);
	//adas1000->setRegisterValue(ADAS1000_FILTCTL, 0x000008);
	//adas1000->setRegisterValue(ADAS1000_ECGCTL, 0xF800AE);
	adas1000->setRegisterValue(ADAS1000_FRMCTL,0x7FFE58);
	adas1000->setRegisterValue(ADAS1000_FRAMES, 0x000000);
	*/

	delay(3000);

	Serial.println(d->read());

	
}

void loop()
{
	unsigned char dataBuffer[4] = { 0, };
	
	//adas1000->readData(dataBuffer, 4, true);

	uint32_t dat = adas1000->getRegisterValue(ADAS1000_FRMCTL);

	Serial.println(dat);

	

	dat = adas1000->getRegisterValue(ADAS1000_FRMCTL);

	Serial.println(dat);
	/*Serial.print(dataBuffer[0]);
	Serial.print(" ");
	Serial.print(dataBuffer[1]);
	Serial.print(" ");
	Serial.print(dataBuffer[2]);
	Serial.print(" ");
	Serial.println(dataBuffer[3]);*/

	
	delay(100000);


	
}
