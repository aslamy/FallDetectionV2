// 
// 
// 

#include "ECG500HzCapture.h"

ECG500HzCapture::ECG500HzCapture()
	: ECGCapture()
{
	adas1000->setFRMCTL_Skip4thFrame();
}

double ECG500HzCapture::read(double s)
{
	return 5.0;
}
