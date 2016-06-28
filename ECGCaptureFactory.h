// ECGCaptureFactory.h

#ifndef _ECGCAPTUREFACTORY_h
#define _ECGCAPTUREFACTORY_h

#include "ECGCapture.h"
#include "ECG250HzCapture.h"
#include "ECG500HzCapture.h"
#include "ECG1000HzCapture.h"
#include "ECG2000HzCapture.h"


#include "ECG250HzLead1Capture.h"
#include "ECG250HzLead2Capture.h"
#include "ECG250HzLead3Capture.h"

#include "ECG500HzLead1Capture.h"
#include "ECG500HzLead2Capture.h"
#include "ECG500HzLead3Capture.h"

#include "ECG1000HzLead1Capture.h"
#include "ECG1000HzLead2Capture.h"
#include "ECG1000HzLead3Capture.h"

#include "ECG2000HzLead1Capture.h"
#include "ECG2000HzLead2Capture.h"
#include "ECG2000HzLead3Capture.h"


#include "TestToneSquareWave250HzLead1Capture.h"
#include "TestToneSquareWave250HzLead2Capture.h"
#include "TestToneSquareWave250HzLead3Capture.h"

#include "TestTone10SinWave250HzLead1Capture.h"
#include "TestTone10SinWave250HzLead2Capture.h"
#include "TestTone10SinWave250HzLead3Capture.h"

#include "TestTone150SinWave250HzLead1Capture.h"
#include "TestTone150SinWave250HzLead2Capture.h"
#include "TestTone150SinWave250HzLead3Capture.h"

#include "HashMap.h"
#include "SharedPreferences.h"

class ECGCaptureFactory
{
public:
	static ECGCapture* createECGCapture(String mode, String rate, String lead);
	
	
private:
	static HashMap<String, ECGCapture*> *createMap();

};


#endif
