// 
// 
// 

#include "ECG250HzLead3Capture.h"



void ECG250HzLead3Capture::initialize()
{
	ECG250HzCapture::initialize();
	adas1000->setFRMCTL_DataLeadIIIEnabled(true);
}
