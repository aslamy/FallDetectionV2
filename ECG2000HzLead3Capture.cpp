// 
// 
// 

#include "ECG2000HzLead3Capture.h"


void ECG2000HzLead3Capture::initialize()
{
	ECG2000HzCapture::initialize();
	adas1000->setFRMCTL_DataLeadIIIEnabled(true);
}
