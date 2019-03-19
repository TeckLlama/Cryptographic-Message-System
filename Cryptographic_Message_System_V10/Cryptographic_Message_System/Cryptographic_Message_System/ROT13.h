#pragma once
#include <iostream>
#include <string>
class ROT13
{
public:
	void encryptROT13(std::string message);
	void decryptROT13(std::string message);
	std::string rot13ToSave;
};