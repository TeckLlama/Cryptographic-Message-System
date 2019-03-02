// Auther: Elliot Rihan
// Created: 19/02/19
// Last Modified Date: 
// Description: C++ program 
// Cryptographic_Message_System.cpp: This file contains the 'main' function. Program execution begins and ends there.


#include "pch.h"
//#include "User.h"
//#include "Time.h"
#include <iostream>
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
string userAgeString;

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
	cout << "\n" << fileName << " has been saved\n";
}
ifstream inputUserProfileFile;

void openProfile()
{
	cout << "Enter your Username --> ";
	cin >> username;
	inputUserProfileFile.open(username + ".txt");
	if (inputUserProfileFile.fail())
	{
		do {
			cout << "Couldn't open Profile " << endl;
			cout << "Enter your Username --> ";
			cin >> username;
			inputUserProfileFile.open(username + ".txt");
		} while (!inputUserProfileFile.is_open());
	}

	getline(inputUserProfileFile, username);
	getline(inputUserProfileFile, userFirstName);
	getline(inputUserProfileFile, userLastName);
	getline(inputUserProfileFile, userAgeString);
	getline(inputUserProfileFile, userTime);
	getline(inputUserProfileFile, userEncryption);
	getline(inputUserProfileFile, userMessage);
	inputUserProfileFile.close();
	cout << "User Login Sucessfull!\n";
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
	// There for test to print userProfile before saving
	//cout << "\n" << userProfile
}

void userLogIn()
{
	cinYesOrNo("Do you have an account already? ");
	if (yesOrNo == 'Y' || yesOrNo == 'y')
	{
		openProfile();
	}
	else
	{
		createUserProfile();
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
	encryptDecryptXOR(userMessage, userLastName);

	encryptDecryptROT13(userMessage);

	std::cout << "\n\nHello World!\n";
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
