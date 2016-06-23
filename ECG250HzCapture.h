// ECG250HzCapture.h

#ifndef _ECG250HZCAPTURE_h
#define _ECG250HZCAPTURE_h

#include "ECGCapture.h"

class ECG250HzCapture : public ECGCapture
{
public:
	LinkedList<float> read(int size);
	void initialize(void);
private:
};

#endif

