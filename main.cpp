#include <iostream>
#include "server/server.h"

int main()
{
	int port = 3879;
	uint max_connections = 16;

	Server* server = new Server(max_connections, port, port);
	server->run();

	delete server;
    return 0;
}
