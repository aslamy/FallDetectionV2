// ECGCapture.h

#ifndef _ECGCAPTURE_h
#define _ECGCAPTURE_h

#include "DataCapture.h"
#include "ADAS1000.h"

enum LeadFormat
{
	ELECTRODE = 0,
	DIGITAL = 1
};

class ECGCapture : public DataCapture<double>
{
public:
	ECGCapture();
	double read();
	void setLeadDataCapture(uint8_t lead);
	
	virtual ~ECGCapture();
protected:
	ADAS1000 *adas1000;
	
};


#endif
