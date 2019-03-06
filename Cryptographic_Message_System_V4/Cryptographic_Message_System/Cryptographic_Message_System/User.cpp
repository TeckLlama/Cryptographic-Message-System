#include "pch.h"
#include "User.h"
#include "Time.h"
#include "SaveFile.h"

#include <iostream>
#include <string>
#include <fstream>

Time a;
SaveFile sF;

void User::cinYesOrNo(std::string yNQuestion)
{ // cinYesOrNo is used to get input of Y or N from user 
	do {
		std::cout << yNQuestion << "[Y/N] --> ";
		std::cin >> yesOrNo;
	} while (std::cin.fail() && yesOrNo != 'y' && yesOrNo != 'n' && yesOrNo != 'Y' && yesOrNo != 'N');
	std::cin.ignore();
}

void User::openProfile()
{
	std::ifstream inputUserProfileFile;
	std::cout << "Enter your Username --> ";
	std::cin >> username;
	inputUserProfileFile.open(username + ".txt");
	if (inputUserProfileFile.fail())
	{
		do {
			std::cout << "Couldn't open Profile \n";
			std::cout << "Enter your Username --> ";
			std::cin >> username;
			inputUserProfileFile.open(username + ".txt");
		} while (!inputUserProfileFile.is_open());
	}
	std::getline(inputUserProfileFile, username);
	std::getline(inputUserProfileFile, userFirstName);
	std::getline(inputUserProfileFile, userLastName);
	std::getline(inputUserProfileFile, userAgeString);
	std::getline(inputUserProfileFile, a.userTimeHHMMSS);
	std::getline(inputUserProfileFile, userEncryption);
	if (userEncryption != "XOR" && userEncryption != "ROT13" && userEncryption != "ROT47")
	{
		std::cout << "Error in saved profile check text file or create new profile\n";
		userLogIn();
	}
	std::getline(inputUserProfileFile, userMessage);
	inputUserProfileFile.close();
	std::cout << "User Login Sucessfull!\n";
}

void User::createUserProfile()
{
	std::cout << "Enter a Username --> ";
	std::getline (std::cin, username);
	std::cout << "Enter First Name --> ";
	std::getline (std::cin, userFirstName);
	std::cout << "Enter Last Name  --> ";
	std::getline (std::cin, userLastName);
	std::cout << "Enter Age        --> ";
	std::cin >> userAge;
	std::cin.ignore();
	std::cin.clear();
	a.timeHHMMSS();
	std::cout << "Encryption Methods XOR, ROT13, ROT47, more to be added\n";
	std::cout << "Enter Encryption --> ";
	std::getline (std::cin, userEncryption);
	if (userEncryption != "XOR" && userEncryption != "ROT13" && userEncryption != "ROT47")
	{
		do {
			std::cout << "Error Enter Encryption --> ";
			std::getline(std::cin, userEncryption);
		} while (std::cin.fail() && userEncryption != "XOR" && userEncryption != "ROT13" && userEncryption != "ROT47");
	}
	std::cout << "Enter Message    --> ";
	std::getline (std::cin, userMessage);
	//usernameList =+ username + "";
	userProfile = username + "\n" + userFirstName + "\n" + userLastName + "\n" + std::to_string(userAge) + "\n" + a.userTimeHHMMSS + "\n" + userEncryption + "\n" + userMessage;
	sF.saveFile(username, userProfile);
	// There for test to print userProfile before saving
	//std::cout << "\n" << userProfile
}

void User::userLogIn()
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



