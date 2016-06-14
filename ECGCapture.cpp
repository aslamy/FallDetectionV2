// 
// 
// 

#include "ECGCapture.h"


ECGCapture::ECGCapture(LeadFormat leadFormat)
{

	adas1000.setRegisterValue(ADAS1000_CMREFCTL, 0x85E0004B);
	adas1000.setRegisterValue(ADAS1000_FILTCTL, 0x8B000000);
}

double ECGCapture::read()
{
	return 333.33;
}

LeadFormat ECGCapture::getLeadFormat()
{
	return leadFormat;
}

void ECGCapture::setLeadFormat(LeadFormat leadFormat)
{
	this->leadFormat = leadFormat;
}



ECGCapture::~ECGCapture()
{
}
