#include "Message.h"
#include "pch.h"
#include "ROT13.h"
#include "ROT47.h"
#include "XOR.h"
#include "SaveFile.h"
#include "User.h"

XOR x;
ROT13 r;
ROT47 R;
SaveFile sF2;

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
			sF2.saveFile("./DecryptedXOR", "XOR\n" + x.encryptDecryptMessageXOR);


		}
		if (encryptionMethod == "ROT13")
		{
			r.decryptROT13(encryptedMessage);
			sF2.saveFile("./DecryptedROT13", "ROT13\n" + r.decryptROT13);

		}
		if (encryptionMethod == "ROT47")
		{
			R.decryptROT47(encryptedMessage);
			sF2.saveFile("./DecryptedROT47", "ROT47\n" + R.decryptROT47);


		}
	}
}

void Message::encryptMessage(User t2)
{
	if (t2.userEncryption == "XOR")
	{
		x.encryptXOR(t2.userMessage, t2.userLastName);
		sF2.saveFile("./EncryptedXOR", "XOR\n" + x.encryptDecryptMessageXOR);

	}
	if (t2.userEncryption == "ROT13")
	{
		r.encryptROT13(t2.userMessage);
		sF2.saveFile("./EncryptedROT13", "ROT13\n" + r.encryptedROT13String);

	}
	if (t2.userEncryption == "ROT47")
	{
		R.encryptROT47(t2.userMessage);
		sF2.saveFile("./EncryptedROT47", "ROT47\n" + R.encryptedROT47);

	}
}				

