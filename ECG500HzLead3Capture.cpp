// 
// 
// 

#include "ECG500HzLead3Capture.h"


void ECG500HzLead3Capture::initialize()
{
	ECG500HzCapture::initialize();
	adas1000->setFRMCTL_DataLeadIIIEnabled(true);
}
