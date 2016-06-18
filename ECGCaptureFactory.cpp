// 
// 
// 

#include "ECGCaptureFactory.h"

ECGCapture* ECGCaptureFactory::createECGCapture()
{
	HashMap<String,ECGCapture*> *map = createMap();
	SharedPreferences *shared = SharedPreferences::getInstance();
	String mode = shared->getString("ADAS1000_MODE","ECG");
	String rate = shared->getString("ADAS1000_DATA_RATE", "250Hz");
	String modeRate = mode + rate;
	String lead = shared->getString("ADAS1000_LEAD", "LEAD1");
	ECGCapture *ecg = map->get(modeRate);
	 
	if(ecg)
	{
		if (lead.equals("LEAD3"))
		{
			ecg->setLeadIEnabled();
			return  ecg;
		}
		if (lead.equals("LEAD2"))
		{
			ecg->setLeadIEnabled();
			return  ecg;
		}
		ecg->setLeadIEnabled();
		return ecg;
		
	}
	return new ECGCapture();
}


HashMap<String, ECGCapture*>* ECGCaptureFactory::createMap()
{
	HashMap<String, ECGCapture*> *map = new HashMap<String, ECGCapture*>();
	map->put("ECG250Hz", new ECG250HzCapture());
	map->put("ECG500Hz", new ECG500HzCapture());
	map->put("ECG1000Hz", new ECG1000HzCapture());
	map->put("ECG2000Hz", new ECG2000HzCapture());

	map->put("TestTone10SinWave250Hz", new TestTone10SinWave250HzCapture());
	map->put("TestTone10SinWave500Hz", new TestTone10SinWave500HzCapture());
	map->put("TestTone10SinWave1000Hz", new TestTone10SinWave1000HzCapture());
	map->put("TestTone10SinWave2000Hz", new TestTone10SinWave2000HzCapture());

	map->put("TestTone150SinWave250Hz", new TestTone150SinWave250HzCapture());
	map->put("TestTone150SinWave500Hz", new TestTone150SinWave500HzCapture());
	map->put("TestTone150SinWave1000Hz", new TestTone150SinWave1000HzCapture());
	map->put("TestTone150SinWave2000Hz", new TestTone150SinWave2000HzCapture());

	map->put("TestToneSquareWave250Hz", new TestToneSquareWave250HzCapture());
	map->put("TestToneSquareWave500Hz", new TestToneSquareWave500HzCapture());
	map->put("TestToneSquareWave1000Hz", new TestToneSquareWave1000HzCapture());
	map->put("TestToneSquareWave2000Hz", new TestToneSquareWave2000HzCapture());
	return map;
}
