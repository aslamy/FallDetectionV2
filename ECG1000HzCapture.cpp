// 
// 
// 

#include "ECG1000HzCapture.h"


void ECG1000HzCapture::initialize(void)
{
	adas1000->setFRMCTL_Skip2thFrame();
}

