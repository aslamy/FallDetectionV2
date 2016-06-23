// 
// 
// 

#include "GPRSConnection.h"



GPRSConnection::GPRSConnection(String apn, String username, String password)
{
	this->apn = apn;
	this->username = username;
	this->password = password;

}

bool GPRSConnection::connect(void)
{
	return gprsConnection.attachGPRS(apn.c_str(),username.c_str(),password.c_str());
}

void GPRSConnection::disconnect(void)
{
	
}

bool GPRSConnection::isConnected(void)
{
	return false;
}

ConnectionType GPRSConnection::getConnectionType()
{
	return GPRS;
}



