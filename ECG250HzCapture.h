// ECG250HzCapture.h

#ifndef _ECG250HZCAPTURE_h
#define _ECG250HZCAPTURE_h

#include "ECGCapture.h"

class ECG250HzCapture : public ECGCapture
{

public:

	ECG250HzCapture(LeadFormat leadFormat);
	double read();
private:


};



#endif

