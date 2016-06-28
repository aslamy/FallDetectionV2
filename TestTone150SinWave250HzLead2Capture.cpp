// 
// 
// 

#include "TestTone150SinWave250HzLead2Capture.h"


void TestTone150SinWave250HzLead2Capture::initialize()
{
	TestTone250HzCapture::initialize();
	adas1000->setTESTTONE_SineWave150Hz();
	adas1000->setTESTTONE_LLEnabled(true);
	adas1000->setFRMCTL_DataLeadIIEnabled(true);
}
