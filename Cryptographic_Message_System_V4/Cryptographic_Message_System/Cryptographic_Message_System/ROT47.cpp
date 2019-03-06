#include "pch.h"
#include "ROT47.h"
#include "SaveFile.h"
#include <iostream>
#include <string>

SaveFile sF4;

void ROT47::encryptROT47(std::string message)
{
	int key = 47;
	for (int i = 0; i < message.length(); i++) 
	{// loop for message length 
		int tempMessageChar = message[i] + key;
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
	sF4.saveFile("EncryptedROT47", encryptedROT47);
	std::cout << "\nEncrypted Message ROT47\n" << encryptedROT47;
}
void ROT47::decryptROT47(std::string message)
{
	int key = 47;
	std::string decryptedROT47 = "";
	for (int i = 0; i < message.length(); i++) 
	{
		int temp = message[i] - key;
		if (message[i] == 32) 
		{// ignoring space 
			decryptedROT47 += " ";
		}
		else if (temp < 32) 
		{// loops ^ back to ~
			temp += 94;
			decryptedROT47 += temp;
		}
		else 
		{// add decrypted character
			decryptedROT47 += temp;
		} 
	} 
	sF4.saveFile("DecryptedROT47", decryptedROT47);
	std::cout << "\nDecrypted Message ROT47\n" << decryptedROT47;

}
