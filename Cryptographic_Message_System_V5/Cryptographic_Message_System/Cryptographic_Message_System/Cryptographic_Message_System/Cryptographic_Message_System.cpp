// Auther: Elliot Rihan
// Created: 19/02/19
// Last Modified Date: 
// Description: C++ program 
// Cryptographic_Message_System.cpp: This file contains the 'main' function. Program execution begins and ends there.

#include "pch.h"
//#include "stdafx.h"
#include "User.h"
//#include "XOR.h"
//#include "ROT13.h"
//#include "ROT47.h"
#include "Message.h"
#include <iostream>
#include <string>
#include <fstream>

User t;
//XOR x;
//ROT13 r;
//ROT47 R;
Message m;

//
//void encryptionMethod(std::string setEncryption)
//{
//	if (setEncryption == "XOR")
//	{
//		x.encryptDecryptXOR(t.userMessage, t.userLastName);
//	}
//	if (setEncryption == "ROT13")
//	{
//		r.encryptDecryptROT13(t.userMessage);
//	}
//	if (setEncryption == "ROT47")
//	{
//		R.encryptROT47(t.userMessage);
//		//R.decryptROT47(R.encryptedROT47);
//	}
//}

int main()
{
	t.userLogIn();
	m.encryptMessage(t);
	m.decryptMessage(t);

	//encryptionMethod(t.userEncryption);
	//std::cout << "\n\nHello World!\n";
}
