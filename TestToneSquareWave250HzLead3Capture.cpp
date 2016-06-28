// 
// 
// 

#include "TestToneSquareWave250HzLead3Capture.h"


void TestToneSquareWave250HzLead3Capture::initialize()
{
	TestTone250HzCapture::initialize();
	adas1000->setTESTTONE_SquareWave1Hz();
	adas1000->setTESTTONE_RAEnabled(true);
	adas1000->setFRMCTL_DataLeadIIIEnabled(true);
}
