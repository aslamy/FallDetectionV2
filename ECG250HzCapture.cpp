// 
// 
// 

#include "ECG250HzCapture.h"


LinkedList<float> ECG250HzCapture::read(int size)
{
	LinkedList<float> list;
	uint8_t dataBuffer[4] = { 0,0,0,0 };
	int modulus = 0;
	for (int i = 0; i < size * 4; i++)
	{
		bool drdy = true;
		while (drdy)
		{
			adas1000->readFrame(dataBuffer);
			drdy = dataBuffer[0] & 0x40;
		}

		if (dataBuffer[0] < 0x80)
		{
			if (modulus%2) {
				uint32_t data = (dataBuffer[1] << 16) + (dataBuffer[2] << 8) + dataBuffer[3];
				list.add(adas1000->voltageConversion(data, format));
			}
			modulus++;
		}

	}
	return list;
}

void ECG250HzCapture::initialize(void)
{
	ECGCapture::initialize();
	adas1000->setFRMCTL_Skip4thFrame();
}
