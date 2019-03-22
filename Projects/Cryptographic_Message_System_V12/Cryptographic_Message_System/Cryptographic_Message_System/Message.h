// Author: Elliot Rihan
// Created: 19/02/19
// Last Modified Date: 21/03/19
// Description: C++ Class that handles messages from the User Class use with Message.cpp.
// Message.h: This file declares the functions and variables for the Message Class.
#pragma once
#include <iostream>
#include <string>
#include "User.h"


class Message
{
private:
	char yesOrNo;
	std::string fileName;
	std::string encryptionMethod;
	std::string encryptedMessage;
	std::string xorKey;
public:
	void decryptMessage(User t2);
	void encryptMessage(User t2);
	void cinYesOrNo(std::string yNQuestion);
};

