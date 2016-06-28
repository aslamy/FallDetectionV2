// 
// 
// 

#include "TestToneSquareWave250HzLead2Capture.h"


void TestToneSquareWave250HzLead2Capture::initialize()
{
	TestTone250HzCapture::initialize();
	adas1000->setTESTTONE_SquareWave1Hz();
	adas1000->setTESTTONE_LLEnabled(true);
	adas1000->setFRMCTL_DataLeadIIEnabled(true);

}
