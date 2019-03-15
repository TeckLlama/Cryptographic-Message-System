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
private:

};



