// 
// 
// 

#include "TestTone150SinWave250HzLead1Capture.h"


void TestTone150SinWave250HzLead1Capture::initialize()
{
	TestTone250HzCapture::initialize();
	adas1000->setTESTTONE_SineWave150Hz();
	adas1000->setTESTTONE_LAEnabled(true);
	adas1000->setFRMCTL_DataLeadIEnabled(true);
}
