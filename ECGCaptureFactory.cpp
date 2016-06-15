// 
// 
// 

#include "ECGCaptureFactory.h"

ECGCapture* ECGCaptureFactory::createECGCapture()
{
	return new ECG250HzCapture();
}
