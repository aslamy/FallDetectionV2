// 
// 
// 

#include "ECG2000HzCapture.h"


void ECG2000HzCapture::initialize(void)
{
	ECGCapture::initialize();
	adas1000->setFRMCTL_SkipNoneFrame();
}
