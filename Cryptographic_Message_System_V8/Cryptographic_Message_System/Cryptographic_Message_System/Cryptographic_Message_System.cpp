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



User t;
Message m;



int menu()
{
	char eDL;
	do {
		std::cout << "\nEncrypt, Decrypt or Log Out[E/D/L] --> ";
		std::cin >> eDL;
	} while (std::cin.fail() || eDL != 'e' && eDL != 'd' && eDL != 'l' && eDL != 'E' && eDL != 'D'&& eDL != 'L');
	std::cin.ignore();
	if (eDL == 'e' || eDL == 'E')
	{
		m.encryptMessage(t);
		menu();
	}
	if (eDL == 'd' || eDL == 'D')
	{
		m.decryptMessage(t); 
		menu();
	}
	if (eDL == 'l' || eDL == 'L')
	{
		t.profileLogOut();
		User t1;
		t = t1;
		return 0;
 	}


}

int main()
{
	system("Title Cryptographic Message System");
	t.userLogIn();
	menu();
}
