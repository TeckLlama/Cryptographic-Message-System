#include "pch.h"
#include "ROT13.h"
#include "SaveFile.h"
#include "User.h"
#include <iostream>
#include <string>

SaveFile sF2;

void ROT13::encryptDecryptROT13(std::string message)
{
	for (int i = 0; i < (int)message.length(); i++)
	{// for length of message to encrypt 
		for (int shift = 0; shift < 13; shift++)
		{// shifts message characters 13 times
			if ((isalpha(message[i])))
			{// if character alhabetical
				if (message[i] == 'z')
				{// if char z loop to a
					message[i] = 'a';
				}
				if (message[i] == 'Z')
				{// if char Z loop to A
					message[i] = 'A';
				}
				else
				{// add 1 to char
					message[i]++;
				}
			}
		}
	}
	sF2.saveFile("MessageROT13", message);
	std::cout << "\nEncrypted Message ROT13\n" << message;
}
