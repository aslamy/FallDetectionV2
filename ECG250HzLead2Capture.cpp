// 
// 
// 

#include "ECG250HzLead2Capture.h"




void ECG250HzLead2Capture::initialize()
{
	ECG250HzCapture::initialize();
	adas1000->setFRMCTL_DataLeadIIEnabled(true);
}
