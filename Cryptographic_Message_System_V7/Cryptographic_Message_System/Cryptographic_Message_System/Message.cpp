#include "pch.h"
#include "Message.h"
#include <iostream>
#include <string>
#include <fstream>
#include "XOR.h"
#include "ROT13.h"
#include "ROT47.h"
#include "User.h"

XOR x;
ROT13 r;
ROT47 R;

void Message::cinYesOrNo(std::string yNQuestion)
{ // cinYesOrNo is used to get input of Y or N from user 
	do {
		std::cout << yNQuestion << "[Y/N] --> ";
		std::cin >> yesOrNo;
	} while (std::cin.fail() || yesOrNo != 'y' && yesOrNo != 'n' && yesOrNo != 'Y' && yesOrNo != 'N');
	std::cin.ignore();
}

void Message::decryptMessage(User t2)
{
	std::cout << "\nEnsure the text file to decrypt is in the same directory as CMS.exe\n";
	do {
		cinYesOrNo("Is text file in the correct location? ");
	} while (yesOrNo != 'y' && yesOrNo != 'Y');
	std::ifstream inputEncryptedMessage;
	std::cout << "Enter the file name --> ";
	std::cin >> fileName;
	inputEncryptedMessage.open(fileName + ".txt");
	if (inputEncryptedMessage.fail())
	{// if open message fails retry intput
		do {// untill message is open
			std::cout << "Couldn't open Message \n";
			std::cout << "Enter the file name --> ";
			std::cin >> fileName;
			inputEncryptedMessage.open(fileName + ".txt");
		} while (!inputEncryptedMessage.is_open());
	}
	std::getline(inputEncryptedMessage, encryptionMethod);
	std::getline(inputEncryptedMessage, encryptedMessage, (char) inputEncryptedMessage.eof());
	if (encryptionMethod != "XOR" && encryptionMethod != "ROT13" && encryptionMethod != "ROT47")
	{
		std::cout << "Error Encryption Method is not correct check file and start again\n";
		decryptMessage(t2);
	}// lines for testing 
	// std::cout << "\n" + encryptionMethod + "\n";
	// std::cout << "\n" + encryptedMessage + "\n";
	else
	{
		if (encryptionMethod == "XOR")
		{
			std::cout << "Plese enter the XOR Key --> ";
			std::cin >> xorKey;
			x.decryptXOR(encryptedMessage, xorKey);
		}
		if (encryptionMethod == "ROT13")
		{
			r.decryptROT13(encryptedMessage);
		}
		if (encryptionMethod == "ROT47")
		{
			R.decryptROT47(encryptedMessage);
		}
	}

}

void Message::encryptMessage(User t2)
{
	if (t2.userEncryption == "XOR")
	{
		x.encryptXOR(t2.userMessage, t2.userLastName);
	}
	if (t2.userEncryption == "ROT13")
	{
		r.encryptROT13(t2.userMessage);
	}
	if (t2.userEncryption == "ROT47")
	{
		R.encryptROT47(t2.userMessage);
	}
}				

