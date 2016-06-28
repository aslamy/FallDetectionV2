// 
// 
// 

#include "ECG2000HzLead2Capture.h"


void ECG2000HzLead2Capture::initialize()
{
	ECG2000HzCapture::initialize();
	adas1000->setFRMCTL_DataLeadIIEnabled(true);
}
