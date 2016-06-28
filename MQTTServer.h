// Server.h

#ifndef _MQTTSERVER_h
#define _MQTTSERVER_h

#include  "LinkedList.h"
#include "NetworkConnection.h"
#include <PubSubClient.h>
#include <LGPRSClient.h>
#include <LWiFiClient.h>


class MQTTServer
{
public:

	MQTTServer(String host, String port, const String publishChannel, const String subsctibeChannel);
	bool send(String data);
	void addNetworkConnection(NetworkConnection* connection);
	bool isConnected(void);
	void setCallback(void(*callback)(char*, uint8_t*, unsigned int));
	PubSubClient pubSubClient;
protected:
	LinkedList<NetworkConnection*> networkList;

	String host;
	String port;
	String publishChannel;
	String subsctibeChannel;
	bool reconnect(void);
	LWiFiClient wifiClient;
	LGPRSClient gprsClient;
};


#endif

