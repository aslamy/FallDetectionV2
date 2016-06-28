// 
// 
// 

#include "ECG1000HzLead1Capture.h"


void ECG1000HzLead1Capture::initialize()
{
	ECG1000HzCapture::initialize();
	adas1000->setFRMCTL_DataLeadIEnabled(true);
}
