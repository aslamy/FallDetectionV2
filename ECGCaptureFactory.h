// ECGCaptureFactory.h

#ifndef _ECGCAPTUREFACTORY_h
#define _ECGCAPTUREFACTORY_h

#include "ECGCapture.h"
#include "ECG250HzCapture.h"
#include "ECG500HzCapture.h"
#include "ECG1000HzCapture.h"
#include "ECG2000HzCapture.h"
#include "TestTone150SinWave2000HzCapture.h"
#include "TestTone150SinWave1000HzCapture.h"
#include "TestTone150SinWave500HzCapture.h"
#include "TestTone150SinWave250HzCapture.h"
#include "TestTone10SinWave2000HzCapture.h"
#include "TestTone10SinWave1000HzCapture.h"
#include "TestTone10SinWave500HzCapture.h"
#include "TestTone10SinWave250HzCapture.h"

#include "TestToneSquareWave2000HzCapture.h"
#include "TestToneSquareWave1000HzCapture.h"
#include "TestToneSquareWave500HzCapture.h"
#include "TestToneSquareWave250HzCapture.h"
#include "HashMap.h"
#include "SharedPreferences.h"

class ECGCaptureFactory
{
public:
	static ECGCapture* createECGCapture(void);
	
	
private:
	static HashMap<String, ECGCapture*> *createMap();

};


#endif
