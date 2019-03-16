#include "pch.h"
#include "User.h"
#include "Time.h"
#include "XOR.h"
#include "SaveFile.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include"md5.h"

MD5 md5;
Time a;
SaveFile sF;
XOR x0;

void User::cinYesOrNo(std::string yNQuestion)
{ // cinYesOrNo is used to get input of Y or N from user 
	do {
		std::cout << yNQuestion << "[Y/N] --> ";
		std::cin >> yesOrNo;
	} while (std::cin.fail() || yesOrNo != 'y' && yesOrNo != 'n' && yesOrNo != 'Y' && yesOrNo != 'N');
	std::cin.ignore();
}

void User::openProfile()
{
	std::ifstream inputUserProfileFile;
	//std::cout << "Enter your Username --> ";
	//std::cin >> username;
	inputUserProfileFile.open("./Users/" + username + ".txt");
	if (inputUserProfileFile.fail())
	{// if input fails retry intput
		do {// untill profile is open
			std::cout << "Couldn't open Profile \n";
			std::cout << "Enter your Username --> ";
			std::cin >> username;
			inputUserProfileFile.open(username + ".txt");
		} while (!inputUserProfileFile.is_open());
	}//  read user profile line by line
	std::getline(inputUserProfileFile, username);
	std::getline(inputUserProfileFile, userFirstName);
	std::getline(inputUserProfileFile, userLastName);
	std::getline(inputUserProfileFile, userAgeString);
	std::getline(inputUserProfileFile, a.userTimeHHMMSS);
	std::getline(inputUserProfileFile, userEncryption);
	if (userEncryption != "XOR" && userEncryption != "ROT13" && userEncryption != "ROT47")
	{// if userEncryption not valid resets back to userLogin
		std::cout << "Error in saved profile check text file or create new profile\n";
		userLogIn();
	}
	std::getline(inputUserProfileFile, userMessage);
	inputUserProfileFile.close();
	userProfile = username + "\n" + userFirstName + "\n" + userLastName + "\n" + userAgeString + "\n" + a.userTimeHHMMSS + "\n" + userEncryption + "\n" + userMessage;
	std::cout << "User Login Sucessfull!\n";
	cinYesOrNo("Do you want to display profile? ");
	if (yesOrNo == 'Y' || yesOrNo == 'y')
	{
		std::cout << "\n" << userProfile <<"\n";
	}
	/*cinYesOrNo("\nDo you want to update your profile? ");
	if (yesOrNo == 'Y' || yesOrNo == 'y')
		
	{
		updateUserProfile();
	}*/
	
}

void User::generateSaltPassHash()
{
	std::cout << "Enter Username --> ";
	std::cin >> salt;
	std::stringstream ss;
	ss << salt;
	ss >> username;
	std::cout << "Enter Password --> ";
	std::cin >> userPasswordPlainText;
	strcat_s(saltPlusPass, salt);
	strcat_s(saltPlusPass, userPasswordPlainText);
	hashedSaltPassword = md5.digestString(saltPlusPass);
	
}

void User::createUserProfile()
{// getline used for input of strings 
	std::cout << "Enter a Username --> ";
	std::getline (std::cin, username);
	std::cout << "Enter First Name --> ";
	std::getline (std::cin, userFirstName);
	std::cout << "Enter Last Name  --> ";
	std::getline (std::cin, userLastName);
	std::cout << "Enter Age        --> ";
	std::cin >> userAge;// cin to input age
	while (std::cin.fail())
	{// while loop used for error validation
		std::cout << "Error Enter Age --> ";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin >> userAge;
	}
	std::cin.ignore();
	std::cin.clear();
	a.timeHHMMSS();
	std::cout << "Encryption Methods XOR, ROT13, ROT47, more to be added\n";
	std::cout << "Enter Encryption --> ";
	std::getline (std::cin, userEncryption);
	if (userEncryption != "XOR" && userEncryption != "ROT13" && userEncryption != "ROT47")
	{// if userEncryption not valid retry 
		do {// intput untill valid 
			std::cout << "Error Enter Encryption --> ";
			std::getline(std::cin, userEncryption);
		} while (std::cin.fail() || userEncryption != "XOR" && userEncryption != "ROT13" && userEncryption != "ROT47");
	}
	std::cout << "Enter Message    --> ";
	std::getline (std::cin, userMessage);
	generateSaltPassHash();
	sF.saveFile("./Users/" + username + "hash", hashedSaltPassword);
	userProfile = username + "\n" + userFirstName + "\n" + userLastName + "\n" + std::to_string(userAge) + "\n" + a.userTimeHHMMSS + "\n" + userEncryption + "\n" + userMessage;
	sF.saveFile("./Users/"+username, userProfile);
	// COMMENTED OUT for itteration 1 screenshots
	//std::cout << "\n" << userProfile //// There for test to print userProfile before saving worker
}

void User::updateUserProfile()
{
	cinYesOrNo("Do you want to change First Name? ");
	if (yesOrNo == 'Y' || yesOrNo == 'y')
	{
		std::cout << "Enter First Name --> ";
		std::getline(std::cin, userFirstName);
	}
	cinYesOrNo("Do you want to change Last Name? ");
	if (yesOrNo == 'Y' || yesOrNo == 'y')
	{
		std::cout << "Enter Last Name  --> ";
		std::getline(std::cin, userLastName);
	}
	cinYesOrNo("Do you want to change Age? ");
	if (yesOrNo == 'Y' || yesOrNo == 'y')
	{
		std::cout << "Enter Age        --> ";
		std::cin >> userAge;// cin to input age
		std::cin.ignore();
		std::cin.clear();
	}
	cinYesOrNo("Do you want to change Time? ");
	if (yesOrNo == 'Y' || yesOrNo == 'y')
	{
		a.timeHHMMSS();
	}
	cinYesOrNo("Do you want to change Encryption Method? ");
	if (yesOrNo == 'Y' || yesOrNo == 'y')
	{
		std::cout << "Encryption Methods XOR, ROT13, ROT47, more to be added\n";
		std::cout << "Enter Encryption --> ";
		std::getline(std::cin, userEncryption);
		if (userEncryption != "XOR" && userEncryption != "ROT13" && userEncryption != "ROT47")
		{// if userEncryption not valid retry 
			do {// intput untill valid 
				std::cout << "Error Enter Encryption --> ";
				std::getline(std::cin, userEncryption);
			} while (std::cin.fail() && userEncryption != "XOR" && userEncryption != "ROT13" && userEncryption != "ROT47");
		}
	}
	cinYesOrNo("Do you want to change Message? ");
	if (yesOrNo == 'Y' || yesOrNo == 'y')
	{
		std::cout << "Enter Message    --> ";
		std::getline(std::cin, userMessage);
	}
	userProfile = username + "\n" + userFirstName + "\n" + userLastName + "\n" + std::to_string(userAge) + "\n" + a.userTimeHHMMSS + "\n" + userEncryption + "\n" + userMessage;
	sF.saveFile("./Users/" + username, userProfile);
	//std::cout << "\n" << userProfile //// There for test to print userProfile before saving worker
}

void User::profileEncrypt()
{
	std::ifstream inputUserProfileFile;
	//std::cout << "Enter your Username --> ";
	//std::cin >> username;
	inputUserProfileFile.open("./Users/" + username + ".txt");
	if (inputUserProfileFile.fail())
	{// if input fails retry intput
		do {// untill profile is open
			std::cout << "Couldn't open Profile \n";
			std::cout << "Enter your Username --> ";
			std::cin >> username;
			inputUserProfileFile.open(username + ".txt");
		} while (!inputUserProfileFile.is_open());
	}
	std::stringstream strStream;
	strStream << inputUserProfileFile.rdbuf();
	std::string encryptProfile = strStream.str();
	x0.encryptProfileXOR(encryptProfile, username, username);
}

void User::profileDecrypt()
{
	std::ifstream inputUserProfileFile;
	//std::cout << "Enter your Username --> ";
	//std::cin >> username;
	inputUserProfileFile.open("./Users/" + username + ".txt");
	if (inputUserProfileFile.fail())
	{// if input fails retry intput
		do {// untill profile is open
			std::cout << "Couldn't open Profile \n";
			std::cout << "Enter your Username --> ";
			std::cin >> username;
			inputUserProfileFile.open(username + ".txt");
		} while (!inputUserProfileFile.is_open());
	}
	std::stringstream strStream;
	strStream << inputUserProfileFile.rdbuf();
	std::string decryptProfile = strStream.str();
	x0.decryptProfileXOR(decryptProfile, username, username);
}

void User::userLogIn()
{// y/n input to openProfile or createUserProfile
	cinYesOrNo("Do you have an account already? ");
	if (yesOrNo == 'Y' || yesOrNo == 'y')
	{
		generateSaltPassHash();
		std::ifstream inputUserHash;
		//std::cout << "Enter your Username --> ";
		//std::cin >> username;
		inputUserHash.open("./Users/" + username + "hash.txt");
		if (inputUserHash.fail())
		{// if input fails retry intput
			do {// untill profile is open
				generateSaltPassHash();
				inputUserHash.open("./Users/" + username + "hash.txt");
			} while (!inputUserHash.is_open());
		}//  read user profile line by line
		std::getline(inputUserHash, userSavedHash);
		if (userSavedHash == hashedSaltPassword)
		{
			profileDecrypt();
			openProfile();
		}
	}
	else
	{
		createUserProfile();
	}
}
void User::profileLogOut()
{
	profileEncrypt();
}