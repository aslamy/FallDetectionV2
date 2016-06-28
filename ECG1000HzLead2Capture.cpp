// 
// 
// 

#include "ECG1000HzLead2Capture.h"



void ECG1000HzLead2Capture::initialize()
{
	ECG1000HzCapture::initialize();
	adas1000->setFRMCTL_DataLeadIIEnabled(true);
}
