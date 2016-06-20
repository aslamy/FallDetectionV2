// 
// 
// 

#include "ECG1000HzCapture.h"

ECG1000HzCapture::ECG1000HzCapture()
	: ECGCapture()
{
	adas1000->setFRMCTL_Skip2thFrame();
}

