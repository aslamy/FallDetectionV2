// 
// 
// 

#include "ECG500HzLead2Capture.h"




void ECG500HzLead2Capture::initialize()
{
	ECGCapture::initialize();
	adas1000->setFRMCTL_DataLeadIIEnabled(true);
}
