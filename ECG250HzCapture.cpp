// 
// 
// 

#include "ECG250HzCapture.h"


LinkedList<float> ECG250HzCapture::read(int size)
{
	LinkedList<float> list;
	uint8_t dataBuffer[4] = { 0,0,0,0 };
	int makeIt250Hz = 0;
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
			if (makeIt250Hz %2) {
				uint32_t data = (dataBuffer[1] << 16) + (dataBuffer[2] << 8) + dataBuffer[3];
				list.add(adas1000->voltageConversion(data, format));
			}
			makeIt250Hz++;
		}

	}
	return list;
}

float ECG250HzCapture::read()
{
	uint8_t dataBuffer[4] = { 0, 0, 0, 0 };
	for (int i = 0; i < 2; i++){
		do{
			bool drdy = true;
			while (drdy)
			{
				adas1000->readFrame(dataBuffer);
				drdy = dataBuffer[0] & 0x40;
			}

		} while (dataBuffer[0] & 0x80);
	}
	uint32_t data = (dataBuffer[1] << 16) + (dataBuffer[2] << 8) + dataBuffer[3];
	return adas1000->voltageConversion(data, format);
}

void ECG250HzCapture::initialize(void)
{
	ECGCapture::initialize();
	adas1000->setFRMCTL_Skip4thFrame();
}
