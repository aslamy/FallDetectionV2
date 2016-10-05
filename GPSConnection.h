#ifndef _GPSCONNECTION_h
#define _GPSCONNECTION_h
#include "arduino.h"
#include <LGPS.h>
#define GPS LGPS

class GPSConnection
{
public:
	void getPosition(float *latitude, float *longitude);
	char* getGPGGA();
	void powerOn(void);
	void powerOff(void);
private:
	const char *nextToken(const char* src, char* buf);
	gpsSentenceInfoStruct info;
};



#endif