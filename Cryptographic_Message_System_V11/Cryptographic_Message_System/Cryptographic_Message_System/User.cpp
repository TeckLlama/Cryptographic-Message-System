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
//XOR x0;

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
	cinYesOrNo("\nDo you want to update your profile? ");
	if (yesOrNo == 'Y' || yesOrNo == 'y')
		
	{
		updateUserProfile();
	}
	
}

void User::generateSaltPassHash()
{
	std::cout << "\tEnter Username --> ";
	std::cin >> salt;
	std::stringstream ss;
	ss << salt;
	ss >> username;
	std::cout << "\tEnter Password --> ";
	std::cin >> userPasswordPlainText;
	strcat_s(saltPlusPass, salt);
	strcat_s(saltPlusPass, userPasswordPlainText);
	hashedSaltPassword = md5.digestString(saltPlusPass);
	//std::cout << "Test: Hashed SaltPassword\n" + hashedSaltPassword;	
}

void User::createUserProfile()
{// getline used for input of strings 
	std::cout << "\tEnter a Username --> ";
	std::getline (std::cin, username);
	std::cout << "\tEnter First Name --> ";
	std::getline (std::cin, userFirstName);
	std::cout << "\tEnter Last Name  --> ";
	std::getline (std::cin, userLastName);
	std::cout << "\tEnter Age        --> ";
	std::cin >> userAge;// cin to input age
	while (std::cin.fail()|| userAge<0 || userAge >110)
	{// while loop used for error validation
		std::cout << "Error Enter Age --> ";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin >> userAge;
	}
	std::cin.ignore();
	std::cin.clear();
	userAgeString = std::to_string(userAge);
	a.timeHHMMSS();
	std::cout << "Encryption Methods XOR, ROT13, ROT47, more to be added\n";
	std::cout << "\tEnter Encryption --> ";
	std::getline (std::cin, userEncryption);
	if (userEncryption != "XOR" && userEncryption != "ROT13" && userEncryption != "ROT47")
	{// if userEncryption not valid retry 
		do {// intput untill valid 
			std::cout << "Error Enter Encryption --> ";
			std::getline(std::cin, userEncryption);
		} while (std::cin.fail() || userEncryption != "XOR" && userEncryption != "ROT13" && userEncryption != "ROT47");
	}
	std::cout << "\tEnter Message    --> ";
	std::getline (std::cin, userMessage);
	generateSaltPassHash();
	sF.saveFile("./Users/" + username + "hash", hashedSaltPassword);
	userProfile = username + "\n" + userFirstName + "\n" + userLastName + "\n" + userAgeString + "\n" + a.userTimeHHMMSS + "\n" + userEncryption + "\n" + userMessage;
	sF.saveFile("./Users/"+username, userProfile);
	// COMMENTED OUT for itteration 1 screenshots
	//std::cout << "\n" << userProfile //// There for test to print userProfile before saving worker
}

void User::updateUserProfile()
{
	cinYesOrNo("Do you want to change First Name? ");
	if (yesOrNo == 'Y' || yesOrNo == 'y')
	{
		std::cout << "\tEnter First Name --> ";
		std::getline(std::cin, userFirstName);
	}
	cinYesOrNo("Do you want to change Last Name? ");
	if (yesOrNo == 'Y' || yesOrNo == 'y')
	{
		std::cout << "\tEnter Last Name  --> ";
		std::getline(std::cin, userLastName);
	}
	cinYesOrNo("Do you want to change Age? ");
	if (yesOrNo == 'Y' || yesOrNo == 'y')
	{
		std::cout << "\tEnter Age        --> ";
		std::cin >> userAge;// cin to input age
		std::cin.ignore();
		std::cin.clear();
		while (std::cin.fail() || userAge < 0 || userAge >110)
		{// while loop used for error validation
			std::cout << "Error Enter Age --> ";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cin >> userAge;
		}
		userAgeString = std::to_string(userAge);
	}
	cinYesOrNo("Do you want to change Time? ");
	if (yesOrNo == 'Y' || yesOrNo == 'y')
	{// time inputs moved to class 
		a.timeHHMMSS();
	}
	cinYesOrNo("Do you want to change Encryption Method? ");
	if (yesOrNo == 'Y' || yesOrNo == 'y')
	{//validation for encryption methods
		std::cout << "Encryption Methods XOR, ROT13, ROT47, more to be added\n";
		std::cout << "\tEnter Encryption --> ";
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
		std::cout << "\tEnter Message    --> ";
		std::getline(std::cin, userMessage);
	}
	userProfile = username + "\n" + userFirstName + "\n" + userLastName + "\n" + userAgeString + "\n" + a.userTimeHHMMSS + "\n" + userEncryption + "\n" + userMessage;
	sF.saveFile("./Users/" + username, userProfile);
	//std::cout << "\n" << userProfile //// There for test to print userProfile before saving worker
}
// This code was used to encrrypt profile using XOR
// Due to unreliable resaults currently not in use 
//void User::profileEncrypt()
//{
//	std::ifstream inputUserProfileFile;
//	//std::cout << "Enter your Username --> ";
//	//std::cin >> username;
//	inputUserProfileFile.open("./Users/" + username + ".txt");
//	if (inputUserProfileFile.fail())
//	{// if input fails retry intput
//		do {// untill profile is open
//			std::cout << "Couldn't open Profile \n";
//			std::cout << "Enter your Username --> ";
//			std::cin >> username;
//			inputUserProfileFile.open(username + ".txt");
//		} while (!inputUserProfileFile.is_open());
//	}
//	std::stringstream strStream;
//	strStream << inputUserProfileFile.rdbuf();
//	std::string encryptProfile = strStream.str();
//	inputUserProfileFile.close();
//	std::cout << encryptProfile;
//	x0.encryptProfileXOR(encryptProfile, username, username);
//
//}
//void User::profileDecrypt()
//{
//	std::ifstream inputUserProfileFile;
//	//std::cout << "Enter your Username --> ";
//	//std::cin >> username;
//	inputUserProfileFile.open("./Users/" + username + ".txt");
//	if (inputUserProfileFile.fail())
//	{// if input fails retry intput
//		do {// untill profile is open
//			std::cout << "Couldn't open Profile \n";
//			std::cout << "Enter your Username --> ";
//			std::cin >> username;
//			inputUserProfileFile.open(username + ".txt");
//		} while (!inputUserProfileFile.is_open());
//	}
//	std::stringstream strStream;
//	strStream << inputUserProfileFile.rdbuf();
//	std::string decryptProfile = strStream.str();
//	/*std::string decryptProfile;
//	std::getline(inputUserProfileFile, decryptProfile, inputUserProfileFile.eof);*/
//	inputUserProfileFile.close();
//	x0.decryptProfileXOR(decryptProfile, username, username);
//}

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
			std::cout << "Incorrect password or user try again\n";
			userLogIn();
		}
		std::getline(inputUserHash, userSavedHash);
		inputUserHash.close();
		if (userSavedHash == hashedSaltPassword)
		{
			//profileDecrypt();
			openProfile();
		}
		else
		{
			std::cout << "Incorrect password or user try again\n";
			userLogIn();
		}
	}
	else
	{
		createUserProfile();
	}
}
void User::profileLogOut()
{
	std::cout << "\n" + username + " has logged out. Goodbye " + userFirstName;
	std::cout << "\nCMS will close.";
	//profileEncrypt();
}