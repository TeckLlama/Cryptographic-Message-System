#include "pch.h"
#include "ROT13.h"
#include "SaveFile.h"
#include "User.h"
#include <iostream>
#include <string>

SaveFile sF2;

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
	
	sF2.saveFile("./EncryptedROT13", "ROT13\n" + encryptMessage);
	std::cout << "\nEncrypted Message ROT13\n" << encryptMessage;
}

void ROT13::decryptROT13(std::string message)
{
	for (int i = 0; i < (int)message.length(); i++)
	{// for length of message to encrypt 
		for (int shift = 0; shift < 13; shift++)
		{// shifts message characters 13 times
			if ((isalpha(message[i])))
			{// if character alhabetical
				if (message[i] == 'a')
				{// if char z loop to a
					message[i] = 'z';
				}
				if (message[i] == 'A')
				{// if char Z loop to A
					message[i] = 'Z';
				}
				else
				{// add 1 to char
					message[i]--;
				}
			}
		}
	}

	sF2.saveFile("./DecryptedROT13", "ROT13\n" + message);
	std::cout << "\nDecrypted Message ROT13\n" << message;
}

