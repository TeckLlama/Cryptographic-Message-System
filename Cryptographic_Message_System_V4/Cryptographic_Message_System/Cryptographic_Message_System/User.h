#pragma once
#include <iostream>
#include <string>

class User
{
protected:

public:
	void createUserProfile();
	void saveFile(std::string fileName, std::string stringToSave);
	void openProfile();
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



