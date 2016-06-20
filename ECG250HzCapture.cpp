// 
// 
// 

#include "ECG250HzCapture.h"


void ECG250HzCapture::initialize(void)
{
	ECGCapture::initialize();
	adas1000->setFRMCTL_Skip4thFrame();
}
