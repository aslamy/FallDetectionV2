// 
// 
// 

#include "ECGCapture.h"


ECGCapture::ECGCapture()
{
	adas1000 = new ADAS1000();
	format = DIGITAL;
}

LinkedList<float> ECGCapture::read(int size)
{
	LinkedList<float> list ;
	uint8_t dataBuffer[4] = { 0,0,0,0 };
	for(int i = 0;i < size*2;i++)
	{
		bool drdy = true;
		while(drdy)
		{
			adas1000->readFrame(dataBuffer);
			drdy = dataBuffer[0] & 0x40;
		}

		if(dataBuffer[0] < 0x80)
		{
			uint32_t data = (dataBuffer[1] << 16) + (dataBuffer[2] << 8) + dataBuffer[3];
			list.add(adas1000->voltageConversion(data, format));;
		}
	}
	return list;
}

float ECGCapture::read(void)
{
	uint8_t dataBuffer[4] = { 0,0,0,0 };
	do{
		bool dataNotReady = true;
		while (dataNotReady)
		{
			adas1000->readFrame(dataBuffer);
			dataNotReady = dataBuffer[0] & 0x40;
		}

	} while (dataBuffer[0] & 0x80);

	uint32_t data = (dataBuffer[1] << 16) + (dataBuffer[2] << 8) + dataBuffer[3];
	return adas1000->voltageConversion(data, format);
}

void ECGCapture::initialize(void)
{
	adas1000->setECGCTL_SoftwareReset();
	adas1000->setECGCTL_PowerOnEnabled(true);
	adas1000->setECGCTL_ADCConversionEnabled(true);
	adas1000->setECGCTL_ChannelLAEnabled(true);
	adas1000->setECGCTL_ChannelLLEnabled(true);
	adas1000->setECGCTL_ChannelRAEnabled(true);
	adas1000->setECGCTL_HighPerformance2MSPS();
	adas1000->setECGCTL_DifferentialInput();
	adas1000->setECGCTL_VREFBufferEnabled(true);
	adas1000->setECGCTL_MasterMode();

	adas1000->setFRMCTL_DataLeadIEnabled(false);
	adas1000->setFRMCTL_DataLeadIIEnabled(false);
	adas1000->setFRMCTL_DataLeadIIIEnabled(false);
	adas1000->setFRMCTL_DataLeadV1Enabled(false);
	adas1000->setFRMCTL_DataLeadV2Enabled(false);
	adas1000->setFRMCTL_PaceDetectionEnabled(false);
	adas1000->setFRMCTL_RespirationMagnitudeEnabled(false);
	adas1000->setFRMCTL_RespirationPhaseEnabled(false);
	adas1000->setFRMCTL_CRCWordEnabled(false);
	adas1000->setFRMCTL_GPIOWordEnabled(false);
	adas1000->setFRMCTL_LeadOffStatusEnabled(false);
	adas1000->setFRMCTL_ElectrodeFormat();
	adas1000->setFRMCTL_ReadyRepeatEnabled(true);

	adas1000->setCMREFCTL_ShieldDriveEnabled(true);
	adas1000->setCMREFCTL_RightLegDriveEnabled(true);
	adas1000->setCMREFCTL_CommonModeIsDrivenOutEnabled(true);

	adas1000->setFILTCTL_2kHNotchFilterForSPIMasterEnabled(true);
	adas1000->setFILTCTL_2kHNotchFilterEnabled(true);
}

ECGCapture::~ECGCapture()
{
	delete adas1000;
}
