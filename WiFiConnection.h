// WiFiConnection.h

#ifndef _WIFICONNECTION_h
#define _WIFICONNECTION_h
#include "NetworkConnection.h"
#include <LWiFi.h>
#define wifiConnection LWiFi

class WiFiConnection :public NetworkConnection
{
public:

	WiFiConnection(String authentication, String accesspoint, String password);
	bool connect(void);
	void disconnect(void);
	bool isConnected(void);
	ConnectionType getConnectionType(void);

 protected:
	 String authentication;
	 String accesspoint;
	 String password;
};


#endif

