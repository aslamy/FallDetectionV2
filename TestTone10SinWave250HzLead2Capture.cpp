// 
// 
// 

#include "TestTone10SinWave250HzLead2Capture.h"


void TestTone10SinWave250HzLead2Capture::initialize()
{
	TestTone250HzCapture::initialize();
	adas1000->setTESTTONE_SineWave10Hz();
	adas1000->setTESTTONE_LLEnabled(true);
	adas1000->setFRMCTL_DataLeadIIEnabled(true);
}
