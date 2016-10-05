// 
// 
// 

#include "TestTone250HzCapture.h"

void TestTone250HzCapture::initialize(void)
{
	ECG250HzCapture::initialize();
	format = ELECTRODE;
	adas1000->setTESTTONE_ModeEnabled(true);
	adas1000->setTESTTONE_Internal();
	adas1000->setCMREFCTL_LAContributesToCommonModeEnabled(false);
	adas1000->setCMREFCTL_LLContributesToCommonModeEnabled(false);
	adas1000->setCMREFCTL_RAContributesToCommonModeEnabled(false);
	adas1000->setECGCTL_SingleEndedInput();
	adas1000->setFILTCTL_2kHNotchFilterForSPIMasterEnabled(false);
	adas1000->setFILTCTL_2kHNotchFilterEnabled(false);
	adas1000->setFILTCTL_250HzLowPassFilter();
	adas1000->setFRMCTL_ElectrodeFormat();
	setFormat(ELECTRODE);
}

