// 
// 
// 

#include "TestToneSquareWave250HzLead1Capture.h"


void TestToneSquareWave250HzLead1Capture::initialize()
{
	TestTone250HzCapture::initialize();
	adas1000->setTESTTONE_SquareWave1Hz();
	adas1000->setTESTTONE_LAEnabled(true);
	adas1000->setFRMCTL_DataLeadIEnabled(true);
}
