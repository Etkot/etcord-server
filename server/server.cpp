#include <iostream>
#include <algorithm>
#include "server.h"

Server::~Server() {
	delete tcp_server;

	for (uint i = 0; i < clients.size(); i++) {
		delete clients[i];
	}
}

void Server::run() {
	// Start the TCP server
	tcp_server = new TCPServer(tcp_port, max_clients);
	tcp_server->Start();

	// TODO: Start the UDP server

	while (true) {
		while (tcp_server->messages->count() > 0) {
			TCPPacket packet = tcp_server->messages->pop();
			switch (packet.type)
			{
			case TCPPacketType::Connect:
				tcp_connected(packet);
				break;

			case TCPPacketType::Disconnect:
				tcp_disconnected(packet);
				break;

			case TCPPacketType::Message:
				tcp_message(packet);
				break;

			default:
				break;
			}
		}
	}
}

void Server::tcp_connected(TCPPacket packet)
{
	Client* new_client = new Client();
	clients.push_back(new_client);
	clients_tcp.insert({ packet.sender, new_client });

	std::cout << "New client connected" << std::endl;
}

void Server::tcp_disconnected(TCPPacket packet)
{
	Client* client = clients_tcp[packet.sender];
	clients.erase(std::remove(clients.begin(), clients.end(), client), clients.end());
	clients_tcp.erase(packet.sender);
	delete client;

	std::cout << "Client disconnected" << std::endl;
}

void Server::tcp_message(TCPPacket packet)
{
	Client* client = clients_tcp[packet.sender];
	std::cout << "Client sent message (" << packet.length << "): " << packet.data << std::endl;

	if (packet.length == 0) return;

	char message_type = packet.data[0];
	switch (message_type) {
	case TCP_ERROR:
		// Client sent and error message to the server
		// Ignore it
		break;
	case TCP_GET_CHANNELS:

		break;
	case TCP_GET_TEXT_HISTORY:

		break;
	case TCP_CHAT_MESSAGE:
		tcp_server->Send_to_all(packet.data, packet.length);
		break;
	case TCP_VOICE_CHANNEL_JOIN:

		break;
	case TCP_VOICE_CHANNEL_LEAVE:

		break;
	default:
		// Unsupported message type
		tcp_server->Send_to_client(packet.sender, TCP_ERROR, 1);
		break;
	}

	delete [] packet.data;
}
