// 
// 
// 

#include "ECG250HzCapture.h"

ECG250HzCapture::ECG250HzCapture()
	: ECGCapture()
{
	adas1000->setFRMCTL_Skip4thFrame();
}

double ECG250HzCapture::read(double s)
{
	return 2.0;
}
