#include "pch.h"
#include "Time.h"
#include <string>

std::string Time::timeHH()
{// checks input of HH is between 0 & 23 working 
	int intTimeHH;
	std::cout << "Enter Time HH    --> ";
	std::cin >> intTimeHH;
	while (std::cin.fail() || intTimeHH < 0 || intTimeHH > 23)
	{// while loop used for error validation
		std::cout << "Error Enter Time HH --> ";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin >> intTimeHH;
	}
	if (intTimeHH <= 9)
	{
		userTimeHH = "0" + std::to_string(intTimeHH);
	}
	else
	{
		userTimeHH = std::to_string(intTimeHH);
	}
	
	return userTimeHH;
}
	
std::string Time::timeMM()
{// checks input of MM is between 0 & 59 working 
	int intTimeMM;
	std::cout << "Enter Time MM    --> ";
	std::cin >> intTimeMM;
	while (std::cin.fail() || intTimeMM < 0 || intTimeMM > 59)
	{// while loop used for error validation
		std::cout << "Error Enter Time MM --> ";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin >> intTimeMM;
	}
	if (intTimeMM <= 9)
	{
		userTimeMM = "0" + std::to_string(intTimeMM);
	}
	else
	{
		userTimeHH = std::to_string(intTimeMM);
	}
	
	return userTimeMM;
}

std::string Time::timeSS()
{// checks input of SS is between 0 & 59 working 
	int intTimeSS;
	std::cout << "Enter Time SS    --> ";
	std::cin >> intTimeSS;
	while (std::cin.fail() || intTimeSS < 0 || intTimeSS > 59)
	{// while loop used for error validation
		std::cout << "Error Enter Time SS --> ";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin >> intTimeSS;
	}
	if (intTimeSS <= 9)
	{
		userTimeSS = "0" + std::to_string(intTimeSS);
	}
	else
	{
		userTimeSS = std::to_string(intTimeSS);
	}


	return userTimeSS;
}

std::string Time::timeHHMMSS()
{// works but need to add error checking to ensure time is HHMMSS 
 // (if MM entered is 2 will output 12:2:12)
	Time::timeHH();
	Time::timeMM();
	Time::timeSS();
	userTimeHHMMSS = userTimeHH + ':' + userTimeMM + ':' +userTimeSS;

	//if (userTimeHH <= 9 || userTimeMM <= 9 || userTimeSS <= 9)
	//{
	//	if(userTimeHH<=9)
	//	{
	//		userTimeHHMMSS += "0" + std::to_string(userTimeHH) + ":";
	//		if (userTimeMM <= 9)
	//		{
	//			userTimeHHMMSS += "0" + std::to_string(userTimeMM) + ":";
	//			if (userTimeSS <= 9)
	//			{
	//				userTimeHHMMSS += "0" + std::to_string(userTimeSS);
	//			}
	//		}


	//	}


	//}
	//else
	//{
	//}
	std::cin.ignore();
	std::cin.clear();
	return userTimeHHMMSS;
}
