// 
// 
// 

#include "ECGCaptureFactory.h"

ECGCapture* ECGCaptureFactory::createECGCapture(String mode ,String rate ,String lead)
{
	HashMap<ECGCapture*> *map = createMap();
	
	Serial.println(mode);
	Serial.println(rate);
	Serial.println(lead);
	ECGCapture *ecg = map->get(mode + rate + lead);

	if(!ecg)
	{
		Serial.println("ECG is null");
	}

	return (ecg)? ecg : new ECGCapture();
}


HashMap<ECGCapture*>* ECGCaptureFactory::createMap()
{
	HashMap<ECGCapture*> *map = new HashMap<ECGCapture*>();
	map->put("ECG250HzLead1", new ECG250HzLead1Capture());
	map->put("ECG250HzLead2", new ECG250HzLead2Capture());
	map->put("ECG250HzLead3", new ECG250HzLead3Capture());

	map->put("ECG500HzLead1", new ECG500HzLead1Capture());
	map->put("ECG500HzLead2", new ECG500HzLead2Capture());
	map->put("ECG500HzLead3", new ECG500HzLead3Capture());

	map->put("ECG1000HzLead1", new ECG1000HzLead1Capture());
	map->put("ECG1000HzLead2", new ECG1000HzLead2Capture());
	map->put("ECG1000HzLead3", new ECG1000HzLead3Capture());

	map->put("ECG2000HzLead1", new ECG2000HzLead1Capture());
	map->put("ECG2000HzLead2", new ECG2000HzLead2Capture());
	map->put("ECG2000HzLead3", new ECG2000HzLead3Capture());

	map->put("TesttoneSquareWave250HzLead1", new TestToneSquareWave250HzLead1Capture());
	map->put("TestToneSquareWave250HzLead2", new TestToneSquareWave250HzLead2Capture());
	map->put("TestToneSquareWave250HzLead3", new TestToneSquareWave250HzLead3Capture());
	
	map->put("TestTone10SinWave250HzLead1", new TestTone10SinWave250HzLead1Capture());
	map->put("TestTone10SinWave250HzLead2", new TestTone10SinWave250HzLead2Capture());
	map->put("TestTone10SinWave250HzLead3", new TestTone10SinWave250HzLead3Capture());
	
	map->put("TestTone150SinWave250HzLead1", new TestTone150SinWave250HzLead1Capture());
	map->put("TestTone150SinWave250HzLead2", new TestTone150SinWave250HzLead2Capture());
	map->put("TestTone150SinWave250HzLead3", new TestTone150SinWave250HzLead3Capture());
	
	return map;
}
