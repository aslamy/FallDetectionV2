// 
// 
// 

#include "ECG2000HzCapture.h"

ECG2000HzCapture::ECG2000HzCapture()
	: ECGCapture()
{
	adas1000->setFRMCTL_SkipNoneFrame();
}

