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
	return pubSubClient.publish(publishChannel.c_str(),data.c_str());
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
						return reconnect();
					}
					if (network->getConnectionType() == GPRS)
					{
						pubSubClient.setClient(gprsClient);
						return reconnect();
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

bool MQTTServer::reconnect(void)
{
	Serial.println("reconnect 1");
	pubSubClient.setServer(host.c_str(), port.toInt());
	Serial.println("reconnect 2");
	pubSubClient.subscribe(subsctibeChannel.c_str());
	return pubSubClient.connect("LinkIt One"+random(10000));
}
