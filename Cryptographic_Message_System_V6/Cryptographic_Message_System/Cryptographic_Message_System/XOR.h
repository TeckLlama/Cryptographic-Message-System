#pragma once
#include "SaveFile.h"
#include <iostream>
#include <string>

class XOR
{
public:
	void encryptXOR(std::string message, std::string key);
	void decryptXOR(std::string message, std::string key);
	std::string encryptDecryptMessageXOR;


};

