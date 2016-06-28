// 
// 
// 

#include "ECG1000HzLead3Capture.h"


void ECG1000HzLead3Capture::initialize()
{
	ECG1000HzCapture::initialize();
	adas1000->setFRMCTL_DataLeadIIIEnabled(true);
}
