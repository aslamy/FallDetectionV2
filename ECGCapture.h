// ECGCapture.h

#ifndef _ECGCAPTURE_h
#define _ECGCAPTURE_h

#include "ADAS1000.h"
#include "LinkedList.h"
#include "MotionCapture.h"

class ECGCapture 
{
public:
	ECGCapture();
	virtual LinkedList<float> read(int);
	virtual float read(void);
	virtual void initialize(void);
	void setFormat(Leadformat format);
	Leadformat getFormat(void);
	virtual ~ECGCapture();
protected:
	ADAS1000* adas1000;
	Leadformat format;
};


#endif
