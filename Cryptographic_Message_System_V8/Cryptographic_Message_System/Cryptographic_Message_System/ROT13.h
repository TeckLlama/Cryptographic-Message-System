#pragma once
#include <iostream>
#include <string>
#include "pch.h"


class ROT13
{
public:
	std::string encryptedROT13String;
	std::string decryptedROT13String;

	void encryptROT13(std::string message);
	void decryptROT13(std::string message);
};