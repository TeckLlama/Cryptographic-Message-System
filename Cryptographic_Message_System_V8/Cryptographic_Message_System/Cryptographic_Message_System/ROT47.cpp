#include "ROT47.h"
#include "pch.h"
#include "User.h"
#include <iostream>
#include <string>
#include "pch.h"
#include "User.h"

void ROT47::encryptROT47(std::string message)
{
	for (int i = 0; i < message.length(); i++) 
	{// loop for message length 
		int tempMessageChar = message[i] + 47;
		if (message[i] == 32) 
		{// ignoring space 
			encryptedROT47 += " ";
		}
		else if (tempMessageChar > 126) 
		{// loops ~ back to ^
			tempMessageChar -= 94;
			encryptedROT47 += tempMessageChar;
		}
		else 
		{// add encrypted character
			encryptedROT47 += tempMessageChar;
		}
	} 
	std::cout << "\nEncrypted Message ROT47\n" << encryptedROT47;
}

void ROT47::decryptROT47(std::string message)
{
	std::string decryptedROT47 = "";
	for (int i = 0; i < message.length(); i++) 
	{
		int tempMessageChar = message[i] - 47;
		if (message[i] == 32) 
		{// ignore space 
			decryptedROT47 += " ";
		}
		else if (tempMessageChar < 32) 
		{// loops ^ back to ~
			tempMessageChar += 94;
			decryptedROT47 += tempMessageChar;
		}
		else 
		{// add decrypted character
			decryptedROT47 += tempMessageChar;
		} 
	} 
	std::cout << "\nDecrypted Message ROT47\n" << decryptedROT47;
}
