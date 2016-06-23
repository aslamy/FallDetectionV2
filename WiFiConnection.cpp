// 
// 
// 

#include "WiFiConnection.h"


WiFiConnection::WiFiConnection(String authentication, String accesspoint, String password)
{
	this->authentication = authentication;
	this->accesspoint = accesspoint;
	this->password = password;
}

bool WiFiConnection::connect(void)
{
	wifiConnection.begin();

	if(authentication.equalsIgnoreCase("WPA"))
	{
		return wifiConnection.connectWPA(accesspoint.c_str(),password.c_str())>0;
	}
	if(authentication.equalsIgnoreCase("WEP"))
	{
		return wifiConnection.connectWEP(accesspoint.c_str(), password.c_str())>0;
	}
	if(authentication.equalsIgnoreCase("OPEN"))
	{
		return wifiConnection.connect(accesspoint.c_str())>0;
	}
	return false;
}

void WiFiConnection::disconnect(void)
{
	wifiConnection.end();
}

bool WiFiConnection::isConnected(void)
{

	return wifiConnection.status() == LWIFI_STATUS_CONNECTED;
}

ConnectionType WiFiConnection::getConnectionType(void)
{
	return WIFI;
}
