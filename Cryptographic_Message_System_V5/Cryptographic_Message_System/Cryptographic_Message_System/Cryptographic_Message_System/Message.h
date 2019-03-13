#pragma once
#include <iostream>
#include <string>
#include"User.h"


class Message
{
public:
	void decryptMessage(User t2);
	void encryptMessage(User t2);
	void cinYesOrNo(std::string yNQuestion);
	char yesOrNo;
	std::string fileName;
	std::string encryptionMethod;
	std::string encryptedMessage;
	std::string xorKey;

};

