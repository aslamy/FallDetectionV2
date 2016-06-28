// 
// 
// 

#include "TestTone10SinWave250HzLead3Capture.h"

void TestTone10SinWave250HzLead3Capture::initialize()
{
	TestTone250HzCapture::initialize();
	adas1000->setTESTTONE_SineWave10Hz();
	adas1000->setTESTTONE_RAEnabled(true);
	adas1000->setFRMCTL_DataLeadIIIEnabled(true);
}

