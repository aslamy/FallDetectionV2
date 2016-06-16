
#include "LinkitOneFlashFileReader.h"
#include "HashMap.h"
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
#include "LinkedList.h"



LinkitOneFlashFileReader *file;
HashMap<unsigned long, unsigned long> *map2;
void setup()
{
	/* add setup code here */

	Serial.begin(9600);
	




/*	adas1000->setRegisterValue(ADAS1000_CMREFCTL, 0x00000B);
	adas1000->setRegisterValue(ADAS1000_TESTTONE, 0xF8001D);
	//adas1000->setRegisterValue(ADAS1000_FILTCTL, 0x000008);
	//adas1000->setRegisterValue(ADAS1000_ECGCTL, 0xF800AE);
	adas1000->setRegisterValue(ADAS1000_FRMCTL,0x7FFE58);
	adas1000->setRegisterValue(ADAS1000_FRAMES, 0x000000);
	*/


	delay(3000);
	file = new LinkitOneFlashFileReader("test.txt");
	file->write("Hello");
	

	Serial.println("done");



	
}

void loop()
{


	
}
