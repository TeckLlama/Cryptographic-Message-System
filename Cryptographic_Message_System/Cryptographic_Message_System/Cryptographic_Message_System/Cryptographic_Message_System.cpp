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

char yesOrNo;

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
    std::cout << "Hello World!\n"; 
}

