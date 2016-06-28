// 
// 
// 

#include "ECG250HzLead1Capture.h"

void ECG250HzLead1Capture::initialize()
{
	ECG250HzCapture::initialize();
	adas1000->setFRMCTL_DataLeadIEnabled(true);
}
