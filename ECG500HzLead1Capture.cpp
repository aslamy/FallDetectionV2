// 
// 
// 

#include "ECG500HzLead1Capture.h"

ECG500HzLead1Capture::ECG500HzLead1Capture()
	: ECG500HzCapture()
{

}
void ECG500HzLead1Capture::initialize()
{
	ECG500HzCapture::initialize();
	adas1000->setFRMCTL_DataLeadIEnabled(true);
}
