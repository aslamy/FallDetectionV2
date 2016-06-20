// 
// 
// 

#include "ECG500HzLead2Capture.h"


ECG500HzLead2Capture::ECG500HzLead2Capture()
	: ECG500HzCapture()
{

}

void ECG500HzLead2Capture::initialize()
{
	ECGCapture::initialize();
	adas1000->setFRMCTL_Skip4thFrame();
}
