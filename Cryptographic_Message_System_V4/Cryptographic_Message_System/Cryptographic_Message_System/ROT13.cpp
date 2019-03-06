#include "pch.h"
#include "ROT13.h"
#include "SaveFile.h"
#include <iostream>
#include <string>

SaveFile sF2;

void ROT13::encryptDecryptROT13(std::string message)
{
	for (int i = 0; i < (int)message.length(); i++)
	{
		for (int shift = 0; shift < 13; shift++)
		{
			if ((isalpha(message[i])))
			{
				if (message[i] == 'z')
				{
					message[i] = 'a';
				}
				if (message[i] == 'Z')
				{
					message[i] = 'A';
				}
				else
				{
					message[i]++;
				}
			}
		}
	}
	sF2.saveFile("MessageROT13", message);
	std::cout << "\nEncrypted Message ROT13\n" << message;
}
