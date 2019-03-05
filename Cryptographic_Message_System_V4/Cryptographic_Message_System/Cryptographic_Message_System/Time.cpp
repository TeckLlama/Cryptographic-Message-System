#include "pch.h"
#include "Time.h"
#include <string>

int Time::timeHH()
{
	std::cout << "Enter Time HH    --> ";
	std::cin, userTimeHH;
	if (userTimeHH < 0 || userTimeHH < 23)
	{
		do {
			std::cout << "Error Enter Time HH --> ";
			std::cin, userTimeHH;
		} while (userTimeHH > 0 || userTimeHH < 23);
	}
}
	
int Time::timeMM()
{

	std::cout << "Enter Time MM    --> ";
	std::cin, userTimeMM;
	if (userTimeMM < 0 || userTimeMM < 59)
	{
		do {
			std::cout << "Error Enter Time MM --> ";
			std::cin, userTimeMM;
		} while (userTimeMM < 0 || userTimeMM < 59);
	}
}

int Time::timeSS()
{
	std::cout << "Enter Time SS    --> ";
	std::cin, userTimeSS;
	if (userTimeSS < 0 || userTimeSS < 59)
	{
		do {
			std::cout << "Error Enter Time SS --> ";
			std::cin, userTimeSS;
		} while (userTimeSS < 0 || userTimeSS < 59);
	}
}

void Time::timeHHMMSS()
{
	Time::timeHH();
	Time::timeMM();
	Time::timeSS();
	userTimeHHMMSS = userTimeHH + ":" + userTimeMM + ':' + userTimeSS;
}
