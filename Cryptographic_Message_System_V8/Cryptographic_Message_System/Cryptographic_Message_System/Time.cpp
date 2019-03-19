#include "pch.h"
#include "Time.h"
#include <string>

int Time::timeHH()
{// checks input of HH is between 0 & 23 working 
	std::cout << "Enter Time HH    --> ";
	std::cin >> userTimeHH;
	while (std::cin.fail() || userTimeHH < 0 || userTimeHH > 23)
	{// while loop used for error validation
		std::cout << "Error Enter Time HH --> ";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin >> userTimeHH;
	}
	return userTimeHH;
}
	
int Time::timeMM()
{// checks input of MM is between 0 & 59 working 
	std::cout << "Enter Time MM    --> ";
	std::cin >> userTimeMM;
	while (std::cin.fail() || userTimeMM < 0 || userTimeMM > 59)
	{// while loop used for error validation
		std::cout << "Error Enter Time MM --> ";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin >> userTimeMM;
	}
	
	return userTimeMM;
}

int Time::timeSS()
{// checks input of SS is between 0 & 59 working 
	std::cout << "Enter Time SS    --> ";
	std::cin >> userTimeSS;
	while (std::cin.fail() || userTimeSS < 0 || userTimeSS > 59)
	{// while loop used for error validation
		std::cout << "Error Enter Time SS --> ";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin >> userTimeSS;
	}
	return userTimeSS;
}

std::string Time::timeHHMMSS()
{// works but need to add error checking to ensure time is HHMMSS 
 // (if MM entered is 2 will output 12:2:12)
	Time::timeHH();
	Time::timeMM();
	Time::timeSS();
	userTimeHHMMSS = std::to_string(userTimeHH) + ':' + std::to_string(userTimeMM) + ':' + std::to_string(userTimeSS);
	std::cin.ignore();
	std::cin.clear();
	return userTimeHHMMSS;
}
