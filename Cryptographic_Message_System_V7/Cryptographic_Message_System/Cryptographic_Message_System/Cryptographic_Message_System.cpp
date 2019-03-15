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
#include "md5.h"
#include <stdio.h>


int test;
User t;
Message m;
char a[] = "password";




int main()
{
	system("Title Cryptographic Message System");
	MD5 md5;
	puts(md5.digestString(a));
	// print the digest for a binary file on disk.
	//puts(md5.digestFile("C:\\WINDOWS\\notepad.exe"));

	/*t.userLogIn();
	m.encryptMessage(t);
	m.decryptMessage(t);*/
	std::cin >> test;
	//std::cout << "\n\nHello World!\n";
}
