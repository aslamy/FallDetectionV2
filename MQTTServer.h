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

protected:
	LinkedList<NetworkConnection*> networkList;
	PubSubClient pubSubClient;
	String host;
	String port;
	String publishChannel;
	String subsctibeChannel;
	bool reconnect(void);
	LWiFiClient wifiClient;
	LGPRSClient gprsClient;
};


#endif

