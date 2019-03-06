// Auther: Elliot Rihan
// Created: 19/02/19
// Last Modified Date: 
// Description: C++ program 
// Cryptographic_Message_System.cpp: This file contains the 'main' function. Program execution begins and ends there.

#include "pch.h"
//#include "stdafx.h"
#include "User.h"
#include "Time.h" 
#include "SaveFile.h"
#include <iostream>
#include <string>
#include <fstream>

User t;
SaveFile sF2;

std::string encryptDecryptMessageXOR;

void encryptDecryptXOR(std::string message, std::string key)
{ // encryptDecryptXOR uses a for loop and XOR function
	int messageLength = (int)message.length();
	int keyLength = (int)key.length();
	for (int i = 0; i < messageLength; i++)
	{
		encryptDecryptMessageXOR += message[i] ^ (int(key[i % keyLength]));
	}
	sF2.saveFile("MessageXOR", encryptDecryptMessageXOR);
	std::cout << "\nEncrypted Message XOR\n" << encryptDecryptMessageXOR;
}

std::string encryptDecryptMessageROT13;

void encryptDecryptROT13(std::string message)
{
	encryptDecryptMessageROT13 = message;
	for (int i = 0; i < (int)encryptDecryptMessageROT13.length(); i++)
	{
		for (int shift = 0; shift < 13; shift++)
		{
			if ((isalpha(encryptDecryptMessageROT13[i])))
			{
				if (encryptDecryptMessageROT13[i] == 'z')
				{
					encryptDecryptMessageROT13[i] = 'a';
				}
				if (encryptDecryptMessageROT13[i] == 'Z')
				{
					encryptDecryptMessageROT13[i] = 'A';
				}
				else
				{
					encryptDecryptMessageROT13[i]++;
				}
			}
		}
	}
	sF2.saveFile("MessageROT13", encryptDecryptMessageROT13);
	std::cout << "\nEncrypted Message ROT13\n" << encryptDecryptMessageROT13;
}

void encryptionMethod()
{
	if (t.userEncryption == "XOR")
	{
		encryptDecryptXOR(t.userMessage, t.userLastName);
	}
	if (t.userEncryption == "ROT13")
	{
		encryptDecryptROT13(t.userMessage);
	}
}

int main()
{
	t.userLogIn();
	encryptionMethod();
	std::cout << "\n\nHello World!\n";
}
