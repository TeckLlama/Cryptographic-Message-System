// Author: Elliot Rihan
// Created: 19/02/19
// Last Modified Date: 15/03/19
// Description: C++ Class that encrypts strings using XOR use with XOR.h.
// XOR.cpp: This file contains the functions for the XOR class.
#include "pch.h"
#include "XOR.h"
#include "User.h"
#include <iostream>
#include <string>


void XOR::encryptXOR(std::string message, std::string key)
{ // encryptDecryptXOR uses a for loop and XOR function
	std::cout << "\nBy default you last name is used as the XOR Key\n";
	char yesOrNo;
	do {		
		std::cout << "Do you want to change the XOR Key [Y/N] --> ";
		std::cin >> yesOrNo;
	} while (std::cin.fail() || yesOrNo != 'y' && yesOrNo != 'n' && yesOrNo != 'Y' && yesOrNo != 'N');
	std::cin.ignore();
	if (yesOrNo == 'Y' || yesOrNo == 'y')
	{
		std::cout << "\nPlese enter the XOR Key --> ";
		std::cin >> key;
	}
	encryptDecryptMessageXOR = "";
	int messageLength = (int)message.length();
	int keyLength = (int)key.length();
	// for length of message to encrypt 
	for (int i = 0; i < messageLength; i++)
	{// XOR by key character stagered by keyLengtg
		encryptDecryptMessageXOR += message[i] ^ (int(key[i % keyLength]));
	}
	std::cout << "\nEncrypted Message XOR\n" << encryptDecryptMessageXOR;
}

void XOR::decryptXOR(std::string message, std::string key)
{ // encryptDecryptXOR uses a for loop and XOR function
	encryptDecryptMessageXOR = "";
	int messageLength = (int)message.length();
	int keyLength = (int)key.length();
	// for length of message to encrypt 
	for (int i = 0; i < messageLength; i++)
	{// XOR by key character stagered by keyLengtg
		encryptDecryptMessageXOR += message[i] ^ (int(key[i % keyLength]));
	}
	std::cout << "\nDecrypted Message XOR\n" << encryptDecryptMessageXOR;
}

//void XOR::decryptProfileXOR(std::string message, std::string key, std::string username)
//{ // encryptDecryptXOR uses a for loop and XOR function
//	encryptDecryptMessageXOR = "";
//	int messageLength = (int)message.length();
//	int keyLength = (int)key.length();
//	// for length of message to encrypt 
//	for (int i = 0; i < messageLength; i++)
//	{// XOR by key character stagered by keyLengtg
//		encryptDecryptMessageXOR += message[i] ^ (int(key[i % keyLength]));
//	}
//	sF3.saveFile("./Users/"+username, encryptDecryptMessageXOR);
//	
//}
//
//void XOR::encryptProfileXOR(std::string message, std::string key, std::string username)
//{ // encryptDecryptXOR uses a for loop and XOR function
//	encryptDecryptMessageXOR = "";
//	int messageLength = (int)message.length();
//	int keyLength = (int)key.length();
//	// for length of message to encrypt 
//	for (int i = 0; i < messageLength; i++)
//	{// XOR by key character stagered by keyLengtg
//		encryptDecryptMessageXOR += message[i] ^ (int(key[i % keyLength]));
//	}
//	sF3.saveFile("./Users/" + username, encryptDecryptMessageXOR);
//}