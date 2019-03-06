#include "pch.h"
#include "User.h"
#include "Time.h"
#include <iostream>
#include <string>
#include <fstream>

Time a;

void User::saveFile(std::string fileName, std::string stringToSave)
{ // saveFile uses ofstream to save decrypted message to .txt
	std::ofstream fileToSave(fileName + ".txt");
	fileToSave << stringToSave;
	fileToSave.close();
	std::cout << "\n" << fileName << " has been saved\n";
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
	std::cout << "Enter Encryption --> ";
	std::getline (std::cin, userEncryption);
	std::cout << "Enter Message    --> ";
	std::getline (std::cin, userMessage);
	//usernameList =+ username + "";
	userProfile = username + "\n" + userFirstName + "\n" + userLastName + "\n" + std::to_string(userAge) + "\n" + a.userTimeHHMMSS + "\n" + userEncryption + "\n" + userMessage;
	saveFile(username, userProfile);
	// There for test to print userProfile before saving
	//std::cout << "\n" << userProfile
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
	std::getline(inputUserProfileFile, userMessage);
	inputUserProfileFile.close();
	std::cout << "User Login Sucessfull!\n";
}



