// Author: Elliot Rihan
// Created: 25/02/19
// Last Modified Date: 01/03/19
// Description: C++ Class that handles time input from User use with Time.cpp.
// Time.h: This file declairs the functions and variables for the Time class.
#pragma once
#include <iostream>
#include <string>


class Time
{
protected:
	
public:
	std::string userTimeHHMMSS;
	int userTimeHH;
	int userTimeMM;
	int userTimeSS;
	std::string timeHHMMSS();
	std::string timeHH();
	std::string timeMM();
	std::string timeSS();
private:	



};

