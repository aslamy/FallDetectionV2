// 
// 
// 

#include "ECG250HzCapture.h"

ECG250HzCapture::ECG250HzCapture(LeadFormat leadFormat)
	: ECGCapture(leadFormat)
{
}

double ECG250HzCapture::read()
{
	return 5.0;
}
