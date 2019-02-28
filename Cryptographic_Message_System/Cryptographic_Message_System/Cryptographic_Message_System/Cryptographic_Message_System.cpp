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

char yesOrNo;

ifstream inputUserProfile;
string userProfile;

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

using namespace std;

void cinYesOrNo(string yNQuestion)
{ // cinYesOrNo is used to get input of Y or N from user 
	do {
		cout << yNQuestion << "[Y/N] --> ";
		cin >> yesOrNo;
	} while (!cin.fail() && yesOrNo != 'y' && yesOrNo != 'n' && yesOrNo != 'Y' && yesOrNo != 'N');
	cin.ignore();
}


int main()
{
	cout << "Enter a Username --> ";
	cin >> username;
	cout << "Enter First Name --> ";
	cin >> userFirstName;
	cout << "Enter Last Name  --> ";
	cin >> userLastName;
	cout << "Enter Age        --> ";
	cin >> userAge;
	cout << "Enter Time HH    --> ";
	cin >> userTimeHH;
	cout << "Enter Time MM    --> ";
	cin >> userTimeMM;
	cout << "Enter Time SS    --> ";
	cin >> userTimeSS;
	userTime = userTimeHH + ":" + userTimeMM + ":" + userTimeSS;
	cout << "Enter Encryption --> ";
	cin >> userEncryption;
	cout << "Enter Message    --> ";
	cin >> userMessage;

    std::cout << "Hello World!\n"; 
}






void getUserProfile()
{
	inputUserProfile.open("IY1S461_CW1M_APPENDIX_2_PRCW_PRACTCW1.txt");

	while (getline(inputUserProfile, userProfile))
	{
		inputUserProfile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << userProfile << "\n";
	}


	inputUserProfile.close();
	cinYesOrNo("Would you like to see the User Profile? ");
	if (yesOrNo == 'Y' || yesOrNo == 'y')
	{
		cout << "User Profile\n" << userProfile << "\n";
	}
}