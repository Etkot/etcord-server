#ifndef CHATMESSAGE_H
#define CHATMESSAGE_H

#include <string>
#include "client.h"

class ChatMessage
{
public:
	ChatMessage(Client* sender, std::string content) : sender(sender), content(content) {}

private:
	Client* sender;
	std::string content;
};

#endif // CHATMESSAGE_H
