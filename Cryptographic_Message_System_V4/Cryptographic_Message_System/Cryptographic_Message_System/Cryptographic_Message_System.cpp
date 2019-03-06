// Auther: Elliot Rihan
// Created: 19/02/19
// Last Modified Date: 
// Description: C++ program 
// Cryptographic_Message_System.cpp: This file contains the 'main' function. Program execution begins and ends there.


#include "pch.h"
//#include "stdafx.h"
#include "User.h"
#include "Time.h" 
#include <iostream>
#include <string>
#include <fstream>

//#include <math.h>

using namespace std;

User t;

// Variable required for cinYesOrNo(string yNQuestion)
char yesOrNo;
void cinYesOrNo(string yNQuestion)
{ // cinYesOrNo is used to get input of Y or N from user 
	do {
		cout << yNQuestion << "[Y/N] --> ";
		cin >> yesOrNo;
	} while (!cin.fail() && yesOrNo != 'y' && yesOrNo != 'n' && yesOrNo != 'Y' && yesOrNo != 'N');
	cin.ignore();
}

void saveFile(string fileName, string stringToSave)
{ // saveFile uses ofstream to save decrypted message to .txt
	ofstream fileToSave(fileName + ".txt");
	fileToSave << stringToSave;
	fileToSave.close();
	cout << "\n" << fileName << " has been saved\n";
}

void userLogIn()
{
	cinYesOrNo("Do you have an account already? ");
	if (yesOrNo == 'Y' || yesOrNo == 'y')
	{
		t.openProfile();
	}
	else
	{
		t.createUserProfile();
	}
}

string encryptDecryptMessageXOR;

void encryptDecryptXOR(string message, string key)
{ // encryptDecryptXOR uses a for loop and XOR function
	int messageLength = (int)message.length();
	int keyLength = (int)key.length();
	for (int i = 0; i < messageLength; i++)
	{
		encryptDecryptMessageXOR += message[i] ^ (int(key[i % keyLength]));
	}
	saveFile("MessageXOR", encryptDecryptMessageXOR);
	cout << "\nEncrypted Message XOR\n" << encryptDecryptMessageXOR;
}

string encryptDecryptMessageROT13;

void encryptDecryptROT13(string message)
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
	saveFile("MessageROT13", encryptDecryptMessageROT13);
	cout << "\nEncrypted Message ROT13\n" << encryptDecryptMessageROT13;
}

int main()
{
	userLogIn();
	encryptDecryptXOR(t.userMessage, t.userLastName);

	encryptDecryptROT13(t.userMessage);

	std::cout << "\n\nHello World!\n";
}
