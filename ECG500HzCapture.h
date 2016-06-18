// ECG500HzCapture.h

#ifndef _ECG500HZCAPTURE_h
#define _ECG500HZCAPTURE_h

#include "ECGCapture.h"

class ECG500HzCapture : public ECGCapture
{
public:

	ECG500HzCapture();
	double read(double s);
private:
};


#endif
