#pragma once
#include <iostream>
#include <string>
#include "pch.h"
#include "User.h"

class ROT47
{
public:
	void encryptROT47(std::string message);
	void decryptROT47(std::string message);
	std::string encryptedROT47;
	std::string decryptedROT47;
};

