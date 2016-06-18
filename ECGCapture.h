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

class ECGCapture : public DataCapture<double,double>
{
public:
	ECGCapture();
	double read(double);
	void setLeadIEnabled(void);
	void setLeadIIEnabled(void);
	void setLeadIIIEnabled(void);

	virtual ~ECGCapture();
protected:
	ADAS1000* adas1000;
};


#endif
