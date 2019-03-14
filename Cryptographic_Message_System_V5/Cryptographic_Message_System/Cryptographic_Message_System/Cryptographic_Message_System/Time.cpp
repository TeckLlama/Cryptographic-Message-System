#include "pch.h"
#include "Time.h"
#include <string>

int Time::getTimeHH()
{// checks input of HH is between 0 & 23 working 
	std::cout << "Enter Time HH    --> ";
	std::cin >> userTimeHH;
	if (userTimeHH < 0 || userTimeHH > 23)
	{
		do {
			std::cin.ignore();
			std::cin.clear();
			std::cout << "Error Enter Time HH --> ";
			std::cin >> userTimeHH;
		} while (userTimeHH < 0 || userTimeHH > 23);
	}
	return userTimeHH;
}
	
int Time::getTimeMM()
{// checks input of MM is between 0 & 59 working 
	std::cout << "Enter Time MM    --> ";
	std::cin >> userTimeMM;
	if (userTimeMM < 0 || userTimeMM > 59)
	{
		do {
			std::cin.ignore();
			std::cin.clear();
			std::cout << "Error Enter Time MM --> ";
			std::cin >> userTimeMM;
		} while (userTimeMM < 0 || userTimeMM > 59);
	}
	return userTimeMM;
}

int Time::getTimeSS()
{// checks input of SS is between 0 & 59 working 
	std::cout << "Enter Time SS    --> ";
	std::cin >> userTimeSS;
	if (userTimeSS < 0 || userTimeSS > 59)
	{
		do {
			std::cin.ignore();
			std::cin.clear();
			std::cout << "Error Enter Time SS --> ";
			std::cin >> userTimeSS;
		} while (userTimeSS < 0 || userTimeSS > 59);
	}
	return userTimeSS;
}

std::string Time::getTimeHHMMSS()
{// works but need to add error checking to ensure time is HHMMSS 
 // (if MM entered is 2 will output 12:2:12)
	Time::getTimeHH();
	Time::getTimeMM();
	Time::getTimeSS();
	userTimeHHMMSS = std::to_string(userTimeHH) + ':' + std::to_string(userTimeMM) + ':' + std::to_string(userTimeSS);
	std::cin.ignore();
	std::cin.clear();
	return userTimeHHMMSS;
}
