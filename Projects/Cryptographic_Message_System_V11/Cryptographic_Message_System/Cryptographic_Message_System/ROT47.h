// Author: Elliot Rihan
// Created: 25/02/19
// Last Modified Date: 01/03/19
// Description: C++ Class that encrypts strings using ROT47 use with ROT47.cpp.
// ROT47.h: This file declares the functions and variables for the ROT47 Class.
#pragma once

#include <iostream>
#include <string>
class ROT47
{
public:
	void encryptROT47(std::string message);
	void decryptROT47(std::string message);
	std::string encryptedROT47;
	std::string decryptedROT47;
};

