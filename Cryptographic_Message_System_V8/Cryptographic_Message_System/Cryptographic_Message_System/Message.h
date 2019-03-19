#pragma once
#include <iostream>
#include <string>
#include <iostream>
#include <string>
#include <fstream>



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

	//std::string sha256(const std::string str);

};

