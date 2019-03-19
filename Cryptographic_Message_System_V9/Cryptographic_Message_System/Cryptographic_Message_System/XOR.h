#pragma once
#include "SaveFile.h"
#include <iostream>
#include <string>

class XOR
{
public:
	void encryptXOR(std::string message, std::string key);
	void decryptXOR(std::string message, std::string key);
	//void encryptProfileXOR(std::string message, std::string key, std::string username);
	//void decryptProfileXOR(std::string message, std::string key, std::string username);

	std::string encryptDecryptMessageXOR;


};

