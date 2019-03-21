#include "pch.h"
#include "User.h"
#include "SaveFile.h"
#include <iostream>
#include <string>
#include <fstream>


void SaveFile::saveFile(std::string fileName, std::string stringToSave)
{ // saveFile uses ofstream to save decrypted message to .txt
	std::ofstream fileToSave(fileName + ".txt");
	fileToSave << stringToSave;
	fileToSave.close();
	//std::cout << "TEST: Using saveFile class";
	std::cout << "\n" << fileName << " has been saved\n";
}
