// ECGCaptureFactory.h

#ifndef _ECGCAPTUREFACTORY_h
#define _ECGCAPTUREFACTORY_h

#include "ECGCapture.h"
#include "ECG250HzCapture.h"

class ECGCaptureFactory
{

 public:
	 static ECGCapture* createECGCapture(void);
	
};


#endif

