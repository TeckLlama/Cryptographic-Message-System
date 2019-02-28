// Auther: Elliot Rihan
// Created: 19/02/19
// Last Modified Date: 
// Description: C++ program 
// Cryptographic_Message_System.cpp: This file contains the 'main' function. Program execution begins and ends there.


#include "pch.h"
#include "User.h"
#include "Time.h"
#include <iostream>
#include <string>
#include <string>
#include <fstream>

using namespace std;

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

// Variables required for createUserProfile 

string username;
string userFirstName;
string userLastName;
int userAge;
string userTimeHH;
string userTimeMM;
string userTimeSS;
string userTime;
string userEncryption;
string userMessage;
string userProfile;
string usernameList;

void saveFile(string fileName, string stringToSave)
{ // saveFile uses ofstream to save decrypted message to .txt
	ofstream fileToSave(fileName + ".txt");
	fileToSave << stringToSave;
	fileToSave.close();
	cout << "\n\nMessage has been saved\n";
}

void createUserProfile()
{
	cout << "Enter a Username --> ";
	getline(cin, username);
	cout << "Enter First Name --> ";
	getline(cin, userFirstName);
	cout << "Enter Last Name  --> ";
	getline(cin, userLastName);
	cout << "Enter Age        --> ";
	cin >> userAge;
	cin.ignore();
	cin.clear();
	cout << "Enter Time HH    --> ";
	getline(cin, userTimeHH);
	cout << "Enter Time MM    --> ";
	getline(cin, userTimeMM);
	cout << "Enter Time SS    --> ";
	getline(cin, userTimeSS);
	userTime = userTimeHH + ":" + userTimeMM + ":" + userTimeSS;
	cout << "Enter Encryption --> ";
	getline(cin, userEncryption);
	cout << "Enter Message    --> ";
	getline(cin, userMessage);
	usernameList += username + "";
	userProfile = username + "\n" + userFirstName + "\n" + userLastName + "\n" + to_string(userAge) + "\n" + userTime + "\n" + userEncryption + "\n" + userMessage;
	saveFile(username, userProfile);
	cout << "\n" << userProfile;
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
}

string encryptDecryptMessageROT13;

void encryptDecryptROT13(string message)
{
	string encryptDecryptMessageROT13 = message;
	int messageLength = (int)encryptDecryptMessageROT13.length();
	for (int shift = 1; shift < 13; shift++)
	{
		for (int i = 0; i < messageLength; i++)
		{ // this for loop changes the character in the tempEncryptedMessage string
			if (isalpha(encryptDecryptMessageROT13[i]))
			{// isalpha is an built in method to check if a character is in alphabet 
				if (encryptDecryptMessageROT13[i] == 'a')
				{ // this loops back to start of alphabet without it alphabet becomes symbols 
					encryptDecryptMessageROT13[i] = 'z';
				}
				else if (encryptDecryptMessageROT13[i] == 'A')
				{
					encryptDecryptMessageROT13[i] = 'Z';
				}
				else
				{
					encryptDecryptMessageROT13[i]++;
				}
			}
		}		
	}
	saveFile("MessageROT13", encryptDecryptMessageROT13);
	
	
}


int main()
{
	cinYesOrNo("Do you have an account already? ");
	if (yesOrNo == 'Y' || yesOrNo == 'y')
	{
		cout << "Enter your Username --> ";
		cin >> username;
	}
	else
	{
		createUserProfile();
		encryptDecryptXOR(userMessage, userLastName);
		cout << "\n\n" << encryptDecryptMessageXOR;
		encryptDecryptROT13(userMessage);
		cout << "\n\n" << encryptDecryptMessageROT13;
	}
	

    std::cout << "\n\nHello World!\n"; 
}
