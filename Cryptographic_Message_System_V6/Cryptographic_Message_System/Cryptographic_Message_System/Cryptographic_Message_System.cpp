// Author: Elliot Rihan
// Created: 19/02/19
// Last Modified Date: 
// Description: C++ program 
// Cryptographic_Message_System.cpp: This file contains the 'main' function. Program execution begins and ends there.

#include "pch.h"
#include "User.h"
#include "Message.h"
#include <iostream>
#include <string>
#include <fstream>


User t;
Message m;

int main()
{
	system("Title Cryptographic Message System");

	t.userLogIn();
	m.encryptMessage(t);
	m.decryptMessage(t);
	//std::cout << "\n\nHello World!\n";
}
