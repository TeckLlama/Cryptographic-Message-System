#include "pch.h"
#include "XOR.h"
#include "SaveFile.h"
#include "User.h"
#include <iostream>
#include <string>
SaveFile sF3;

void XOR::encryptXOR(std::string message, std::string key)
{ // encryptDecryptXOR uses a for loop and XOR function
	encryptDecryptMessageXOR = "";
	int messageLength = (int)message.length();
	int keyLength = (int)key.length();
	// for length of message to encrypt 
	for (int i = 0; i < messageLength; i++)
	{// XOR by key character stagered by keyLengtg
		encryptDecryptMessageXOR += message[i] ^ (int(key[i % keyLength]));
	}
	sF3.saveFile("./EncryptedXOR", "XOR\n" + encryptDecryptMessageXOR);
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
	sF3.saveFile("./DecryptedXOR", "XOR\n" + encryptDecryptMessageXOR);
	std::cout << "\nDecrypted Message XOR\n" << encryptDecryptMessageXOR;
}