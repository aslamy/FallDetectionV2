// 
// 
// 

#include "ECG2000HzLead1Capture.h"


void ECG2000HzLead1Capture::initialize()
{
	ECG2000HzCapture::initialize();
	adas1000->setFRMCTL_DataLeadIEnabled(true);
}
