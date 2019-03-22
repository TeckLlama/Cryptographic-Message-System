// Author: Elliot Rihan
// Created: 25/02/19
// Last Modified Date: 01/03/19
// Description: C++ Class that encrypts saves strings to s text file use with SaveFile.h.
// SaveFile.cpp: This file contains the functions for the SaveFile class.
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
