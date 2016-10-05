// 
// 
// 

#include "MQTTServer.h"

MQTTServer::MQTTServer(String host, String port, const String publishChannel, const String subsctibeChannel)
{
	this->host = host;
	this->port = port;
	this->publishChannel = publishChannel;
	this->subsctibeChannel = subsctibeChannel;
	
}

bool MQTTServer::send(String data)
{
	return pubSubClient.publish(publishChannel.c_str(), data.c_str());
}

void MQTTServer::addNetworkConnection(NetworkConnection * connection)
{
	networkList.add(connection);
}

bool MQTTServer::isConnected(void)
{
	if(!pubSubClient.loop())
	{
		for(int i = 0;i<networkList.size();i++)
		{
			NetworkConnection *network = networkList.get(i);

			if(network->connect())
			{
				if (!pubSubClient.loop())
				{
					if (network->getConnectionType() == WIFI)
					{
						pubSubClient.setClient(wifiClient);
						return connect();
					}
					if (network->getConnectionType() == GPRS)
					{
						pubSubClient.setClient(gprsClient);
						return connect();
					}
				}else
				{
					return true ;
				}
			}else
			{
				network->disconnect();
			}
		}
		return false;
	};

	return true;
}

void MQTTServer::setCallback(void(*callback)(char *, uint8_t *, unsigned int))
{
	pubSubClient.setCallback(callback);
}


bool MQTTServer::connect(void)
{
	
	pubSubClient.setServer(host.c_str(), port.toInt());
	bool connect = pubSubClient.connect("LinkIt One"+random(10000));
	pubSubClient.subscribe(subsctibeChannel.c_str());
	return connect;
}
