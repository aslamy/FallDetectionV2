// 
// 
// 

#include "ECG500HzLead3Capture.h"

ECG500HzLead3Capture::ECG500HzLead3Capture()
	: ECG500HzCapture()
{

}
void ECG500HzLead3Capture::initialize()
{
	ECG500HzCapture::initialize();
	adas1000->setFRMCTL_DataLeadIIIEnabled(true);
}
