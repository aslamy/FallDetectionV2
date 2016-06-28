// 
// 
// 

#include "ECG500HzLead1Capture.h"


void ECG500HzLead1Capture::initialize()
{
	ECG500HzCapture::initialize();
	adas1000->setFRMCTL_DataLeadIEnabled(true);
}
