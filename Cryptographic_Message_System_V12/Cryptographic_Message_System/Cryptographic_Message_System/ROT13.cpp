// Author: Elliot Rihan
// Created: 19/02/19
// Last Modified Date: 18/03/19
// Description: C++ Class that encrypts strings using ROT13 use with ROT13.h.
// ROT13.cpp: This file contains the functions for the ROT13 class.
#include "pch.h"
#include "ROT13.h"
#include "User.h"
#include <iostream>
#include <string>


void ROT13::encryptROT13(std::string encryptMessage)
{
	for (int i = 0; i < (int)encryptMessage.length(); i++)
	{// for length of message to encrypt 
		for (int shift = 0; shift < 13; shift++)
		{// shifts message characters 13 times
			if ((isalpha(encryptMessage[i])))
			{// if character alhabetical
				if (encryptMessage[i] == 'z')
				{// if char z loop to a
					encryptMessage[i] = 'a';
				}
				if (encryptMessage[i] == 'Z')
				{// if char Z loop to A
					encryptMessage[i] = 'A';
				}
				else
				{// add 1 to char
					encryptMessage[i]++;
				}
			}
		}
	}	
	rot13ToSave = encryptMessage;
	std::cout << "\nEncrypted Message ROT13\n" << rot13ToSave;
}

void ROT13::decryptROT13(std::string decryptMessage)
{
	for (int i = 0; i < (int)decryptMessage.length(); i++)
	{// for length of message to encrypt 
		for (int shift = 0; shift < 13; shift++)
		{// shifts message characters 13 times
			if ((isalpha(decryptMessage[i])))
			{// if character alhabetical
				if (decryptMessage[i] == 'a')
				{// if char z loop to a
					decryptMessage[i] = 'z';
				}
				if (decryptMessage[i] == 'A')
				{// if char Z loop to A
					decryptMessage[i] = 'Z';
				}
				else
				{// add 1 to char
					decryptMessage[i]--;
				}
			}
		}
	}
	rot13ToSave = decryptMessage;
	std::cout << "\nDecrypted Message ROT13\n" << rot13ToSave;
}