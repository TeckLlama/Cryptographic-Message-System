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

