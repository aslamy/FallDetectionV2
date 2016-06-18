// ECG250HzCapture.h

#ifndef _ECG250HZCAPTURE_h
#define _ECG250HZCAPTURE_h

#include "ECGCapture.h"

class ECG250HzCapture : public ECGCapture
{
public:

	ECG250HzCapture();
	double read(double s);
private:
};


#endif
