#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <stdint.h>
#include <netinet/in.h>
#include <vector>
#include <thread>
#include "utils/safequeue.h"
#include "tcppacket.h"

class TCPServer
{
public:
	// Constructor and deconstructor
	TCPServer(uint16_t port, uint max_clients) : port(port), max_clients(max_clients) {}
	~TCPServer();


	// Variables
	std::vector<int> client_sockets;
	SafeQueue<TCPPacket>* messages;


	// Methods
	bool Start();

	bool Send_to_client(int socket, char* message, int length);
	bool Send_to_all(char* message, int length, int socket_excluded = 0);

private:
	// Variables
	uint16_t port;
	uint max_clients;

	struct sockaddr_in address;
	int addrlen;

	int master_socket;

	bool running;
	std::thread* listen_thread;


	// Methods
	void Listen();
	void Handle_new_connection();

	void Close_all_connections();
};

#endif // TCPSERVER_H
