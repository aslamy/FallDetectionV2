// 
// 
// 

#include "ECGCapture.h"


ECGCapture::ECGCapture()
{
	adas1000 = new ADAS1000();

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

	adas1000->setFRMCTL_DataLeadIEnabled(true);
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
	
	adas1000->setCMREFCTL_ShieldDriveEnabled(true);
	adas1000->setCMREFCTL_RightLegDriveEnabled(true);
	adas1000->setCMREFCTL_CommonModeIsDrivenOutEnabled(true);

	adas1000->setFILTCTL_2kHNotchFilterForSPIMasterEnabled(true);
	adas1000->setFILTCTL_2kHNotchFilterEnabled(true);
}

double ECGCapture::read()
{
	return 333.33;
}

void ECGCapture::setLeadDataCapture(uint8_t lead)
{
}

ECGCapture::~ECGCapture()
{
	delete adas1000;
}
