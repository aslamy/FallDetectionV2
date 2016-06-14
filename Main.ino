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

DataCapture<double> *d;

void setup()
{
	/* add setup code here */

	Serial.begin(9600);



	adas1000 = new ADAS1000();

	adas1000->setRegisterValue(ADAS1000_CMREFCTL, 0x00000B);
	adas1000->setRegisterValue(ADAS1000_TESTTONE, 0xF8001D);
	adas1000->setRegisterValue(ADAS1000_FILTCTL, 0x000008);
	//adas1000->setRegisterValue(ADAS1000_ECGCTL, 0xF800AE);
	adas1000->setRegisterValue(ADAS1000_FRMCTL,0x7FFE58);
	adas1000->setRegisterValue(ADAS1000_FRAMES, 0x000000);

	delay(5000);

	
}

void loop()
{
	unsigned char dataBuffer[4] = { 0, };
	
	//adas1000->readData(dataBuffer, 4, true);

	uint32_t dat = adas1000->getRegisterValue(ADAS1000_ECGCTL);

	Serial.println(dat);
	
	adas1000->setECGCTL_Gain3();



	dat = adas1000->getRegisterValue(ADAS1000_ECGCTL);

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
