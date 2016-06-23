// GPRSConnection.h

#ifndef _GPRSCONNECTION_h
#define _GPRSCONNECTION_h

#include <LGPRS.h>
#include "NetworkConnection.h"
#define gprsConnection LGPRS

class GPRSConnection :public NetworkConnection
{
public:

	GPRSConnection(String apn, String username, String password);
	bool connect(void);
	void disconnect(void);
	bool isConnected(void);
	ConnectionType getConnectionType(void);
protected:
	String apn;
	String username;
	String password;
	
};

#endif

