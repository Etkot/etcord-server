#ifndef SERVER_H
#define SERVER_H

#include <stdint.h>
#include <vector>
#include <map>
#include "tcp/tcpserver.h"
#include "client.h"

class Server
{
public:
	Server(uint max_clients, uint16_t tcp_port, uint16_t udp_port) : max_clients(max_clients), tcp_port(tcp_port), udp_port(udp_port) {}
	~Server();

	void run();

private:
	// Variables
	uint max_clients;

	int tcp_port;
	int udp_port;

	TCPServer* tcp_server;
	std::vector<Client*> clients;
	std::map<int, Client*> clients_tcp;


	// Methods
	void receive_new_packets();

	void tcp_connected(TCPPacket packet);
	void tcp_disconnected(TCPPacket packet);
	void tcp_message(TCPPacket packet);
};

#define TCP_ERROR 0
#define TCP_GET_CLIENTS 1
#define TCP_GET_CHANNELS 2
#define TCP_GET_TEXT_HISTORY 3

#define TCP_CHAT_MESSAGE 10

#define TCP_VOICE_CHANNEL_JOIN 20
#define TCP_VOICE_CHANNEL_LEAVE 21

#endif // SERVER_H
