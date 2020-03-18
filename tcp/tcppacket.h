#ifndef TCPPACKET_H
#define TCPPACKET_H

enum class TCPPacketType { None=0, Connect=1, Disconnect=2, Message=3 };

struct TCPPacket
{
	int sender;
	TCPPacketType type;
	char* data;
	int length;
};

#endif // TCPPACKET_H
