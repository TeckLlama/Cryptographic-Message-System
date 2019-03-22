// Author: Elliot Rihan
// Created: 19/02/19
// Last Modified Date: 21/03/19
// Description: C++ Class that manages a user profile use with User.cpp.
// User.h: This file declares the functions and variables for the User Class.
#pragma once
#include <iostream>
#include <string>

class User
{
protected:
	
public:
	void createUserProfile();
	void openProfile();
	void userLogIn();
	void updateUserProfile();
	void cinYesOrNo(std::string yNQuestion);
	char yesOrNo;
	std::string username;
	std::string userFirstName;
	std::string userLastName;
	int userAge;
	std::string userAgeString;
	std::string userEncryption;
	std::string userMessage;
	std::string userProfile;

	char salt[50];
	char userPasswordPlainText[100];
	char saltPlusPass[150];

	std::string hashedSaltPassword;
	void generateSaltPassHash();

	std::string userSavedHash;

	//void profileEncrypt();
	//void profileDecrypt();

	void profileLogOut();
	//char* passPlusSaltToHash[];

private:

};



