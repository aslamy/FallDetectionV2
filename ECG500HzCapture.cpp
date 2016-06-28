// 
// 
// 

#include "ECG500HzCapture.h"

void ECG500HzCapture::initialize(void)
{
	ECGCapture::initialize();
	adas1000->setFRMCTL_Skip4thFrame();
}
