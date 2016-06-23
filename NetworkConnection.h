// NetworkConnection.h

#ifndef _NETWORKCONNECTION_h
#define _NETWORKCONNECTION_h

enum ConnectionType
{
	WIFI,
	GPRS

};


class NetworkConnection
{
 protected:


 public:
	
	virtual bool connect(void) = 0;
	virtual void disconnect(void) = 0;
	virtual bool isConnected(void) = 0;
	virtual ConnectionType getConnectionType(void) = 0;
	virtual ~NetworkConnection()
	 {
	 }
};


#endif

