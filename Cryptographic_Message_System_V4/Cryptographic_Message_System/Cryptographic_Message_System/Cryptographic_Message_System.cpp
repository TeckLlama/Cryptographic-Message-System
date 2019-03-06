// Auther: Elliot Rihan
// Created: 19/02/19
// Last Modified Date: 
// Description: C++ program 
// Cryptographic_Message_System.cpp: This file contains the 'main' function. Program execution begins and ends there.

#include "pch.h"
//#include "stdafx.h"
#include "User.h"
#include "XOR.h"
#include "ROT13.h"
#include "ROT47.h"
#include <iostream>
#include <string>
#include <fstream>

User t;
XOR x;
ROT13 r;
ROT47 R;

void encryptionMethod()
{
	if (t.userEncryption == "XOR")
	{
		x.encryptDecryptXOR(t.userMessage, t.userLastName);
	}
	if (t.userEncryption == "ROT13")
	{
		r.encryptDecryptROT13(t.userMessage);
	}
	if (t.userEncryption == "ROT47")
	{
		R.encryptROT47(t.userMessage);
		R.decryptROT47(R.encryptedROT47);
	}
}

int main()
{
	t.userLogIn();
	encryptionMethod();
	std::cout << "\n\nHello World!\n";
}
