// Author: Elliot Rihan
// Created: 25/02/19
// Last Modified Date: 01/03/19
// Description: C++ Class that handles time input from User use with Time.h.
// Time.cpp: This file contains the functions for the Time class.
#include "pch.h"
#include "Time.h"
#include <string>

std::string Time::timeHH()
{// checks input of HH is between 0 & 23 working 
	std::cout << "\tEnter Time HH    --> ";
	std::cin >> userTimeHH;
	while (std::cin.fail() || userTimeHH < 0 || userTimeHH > 23)
	{// while loop used for error validation
		std::cout << "Error Enter Time HH --> ";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin >> userTimeHH;
	}
	if (userTimeHH <= 9)
	{
		return "0" + std::to_string(userTimeHH);
	}
	else
	{
		return std::to_string(userTimeHH);
	}
	
}
	
std::string Time::timeMM()
{// checks input of MM is between 0 & 59 working 
	std::cout << "\tEnter Time MM    --> ";
	std::cin >> userTimeMM;
	while (std::cin.fail() || userTimeMM < 0 || userTimeMM > 59)
	{// while loop used for error validation
		std::cout << "Error Enter Time MM --> ";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin >> userTimeMM;
	}
	if (userTimeMM <= 9)
	{
		return "0" + std::to_string(userTimeMM);
	}
	else
	{
		return std::to_string(userTimeMM);
	}
	
}

std::string Time::timeSS()
{// checks input of SS is between 0 & 59 working 
	std::cout << "\tEnter Time SS    --> ";
	std::cin >> userTimeSS;
	while (std::cin.fail() || userTimeSS < 0 || userTimeSS > 59)
	{// while loop used for error validation
		std::cout << "Error Enter Time SS --> ";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin >> userTimeSS;
	}
	if (userTimeSS <= 9)
	{
		return "0" + std::to_string(userTimeSS);
	}
	else
	{
		return std::to_string(userTimeSS);
	}
}

std::string Time::timeHHMMSS()
{// Error checking added to ensure time is HHMMSS 
 // (if MM entered is 2 will output 12:02:12)
	userTimeHHMMSS = timeHH() + ':' + timeMM() + ':' + timeSS();
	std::cin.ignore();
	std::cin.clear();
	return userTimeHHMMSS;
}
