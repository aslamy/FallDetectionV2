// ECGCapture.h

#ifndef _ECGCAPTURE_h
#define _ECGCAPTURE_h

#include "DataCapture.h"
#include "ADAS1000.h"
#include "LinkedList.h"


class ECGCapture : public DataCapture<LinkedList<float>,int>
{
public:
	ECGCapture();
	LinkedList<float> read(int);
	virtual void initialize(void);
	virtual ~ECGCapture();
protected:
	ADAS1000* adas1000;
	Leadformat format;
};


#endif
