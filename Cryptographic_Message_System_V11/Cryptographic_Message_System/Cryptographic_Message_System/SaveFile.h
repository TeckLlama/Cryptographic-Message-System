// Author: Elliot Rihan
// Created: 25/02/19
// Last Modified Date: 01/03/19
// Description: C++ Class that encrypts saves strings to s text file use with SaveFile.cpp.
// SaveFile.h: This file declares the functions and variables for the SaveFile Class.
#pragma once
#include <iostream>
#include <string>
#include <fstream>

class SaveFile
{
public:
	void saveFile(std::string fileName, std::string stringToSave);
};

