#ifndef CHANNEL_H
#define CHANNEL_H

#include <string>
#include <vector>
#include "client.h"
#include "chatmessage.h"

struct Channel
{
	std::string name;
	bool text_chat;
	bool voice_chat;

	std::vector<ChatMessage> text_messages;
	std::vector<Client> voice_clients;
};

#endif // CHANNEL_H
