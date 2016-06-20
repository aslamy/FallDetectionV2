// 
// 
// 

#include "ECG500HzCapture.h"

ECG500HzCapture::ECG500HzCapture()
	: ECGCapture()
{
	adas1000->setFRMCTL_Skip4thFrame();
}


void ECG500HzCapture::initialize(void)
{
	ECGCapture::initialize();
	adas1000->setFRMCTL_Skip4thFrame();
}
