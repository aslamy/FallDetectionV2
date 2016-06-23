// 
// 
// 

#include "ECGCaptureFactory.h"

ECGCapture* ECGCaptureFactory::createECGCapture(String mode ,String rate ,String lead)
{
	HashMap<String,ECGCapture*> *map = createMap();
	ECGCapture *ecg = map->get(mode + rate + lead);
	return (ecg)? ecg : new ECGCapture();
}


HashMap<String, ECGCapture*>* ECGCaptureFactory::createMap()
{
	HashMap<String, ECGCapture*> *map = new HashMap<String, ECGCapture*>();
	map->put("ECG250HzLead1", new ECG250HzLead1Capture());
	map->put("ECG250HzLead2", new ECG250HzLead2Capture());
	map->put("ECG250HzLead3", new ECG250HzLead3Capture());

	map->put("ECG500HzLead1", new ECG500HzLead1Capture());
	map->put("ECG500HzLead2", new ECG500HzLead2Capture());
	map->put("ECG500HzLead3", new ECG500HzLead3Capture());


	map->put("TestTone10SinWave250Hz", new TestTone10SinWave250HzCapture());
	map->put("TestTone150SinWave250Hz", new TestTone150SinWave250HzCapture());
	map->put("TesttoneSquareWave250HzLead1", new TestToneSquareWave250HzLead1Capture());
	
	return map;
}
