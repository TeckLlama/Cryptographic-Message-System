#pragma once
#include <iostream>
#include <string>


class Time
{
protected:
	
public:
	std::string userTimeHHMMSS;
	std::string userTimeHH;
	std::string userTimeMM;
	std::string userTimeSS;

	std::string timeHHMMSS();
	std::string timeHH();
	std::string timeMM();
	std::string timeSS();
private:	



};

