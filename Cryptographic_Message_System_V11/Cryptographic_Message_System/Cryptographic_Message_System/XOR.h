// Author: Elliot Rihan
// Created: 19/02/19
// Last Modified Date: 15/03/19
// Description: C++ Class that encrypts strings using XOR use with XOR.cpp.
// XOR.h: TThis file declares the functions and variables for the XOR Class..
#pragma once
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

