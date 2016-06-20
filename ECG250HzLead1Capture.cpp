// 
// 
// 

#include "ECG250HzLead1Capture.h"

ECG250HzLead1Capture::ECG250HzLead1Capture()
	: ECG250HzCapture()
{
	
}

void ECG250HzLead1Capture::initialize()
{
	ECG250HzCapture::initialize();
	adas1000->setFRMCTL_DataLeadIEnabled(true);
}
