// 
// 
// 

#include "ECG250HzLead3Capture.h"


ECG250HzLead3Capture::ECG250HzLead3Capture()
	: ECG250HzCapture()
{

}

void ECG250HzLead3Capture::initialize()
{
	ECG250HzCapture::initialize();
	adas1000->setFRMCTL_DataLeadIIIEnabled(true);
}
