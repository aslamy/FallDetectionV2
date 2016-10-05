#include "GPSConnection.h"

void GPSConnection::getPosition(float* latitude, float* longitude)
{
	GPS.getData(&info);
	char latit[20];
	char longit[20];
	char buf[20];
	const char* p = (char*)info.GPGGA;
	p = nextToken(p, 0); // GGA
	p = nextToken(p, 0); // Time
	p = nextToken(p, latit); // Latitude
	p = nextToken(p, 0); // N
	p = nextToken(p, longit); // Longitude
	p = nextToken(p, 0); // E
	p = nextToken(p, buf); // fix quality

	//if (buf[0]=='1')
	{
		*latitude = atof(latit) / 100;
		*longitude = atof(longit) / 100;
	}
	//else
	{
		//	*latitude = 0.0;
		//	*longitude = 0.0;
	}
}

char* GPSConnection::getGPGGA()
{
	GPS.getData(&info);
	return (char*)info.GPGGA;
}

void GPSConnection::powerOn()
{
	GPS.powerOn();
}

void GPSConnection::powerOff()
{
	GPS.powerOff();
}

const char* GPSConnection::nextToken(const char* src, char* buf)
{
	int i = 0;
	while (src[i] != 0 && src[i] != ',')
		i++;
	if (buf)
	{
		strncpy(buf, src, i);
		buf[i] = 0;
	}
	if (src[i])
		i++;
	return src + i;
}
