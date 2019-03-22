// Author: Elliot Rihan
// Created: 19/02/19
// Last Modified Date: 18/03/19
// Description: C++ Class that encrypts strings using ROT13 use with ROT13.cpp.
// ROT13.h: This file declares the functions and variables for the ROT13 Class.
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