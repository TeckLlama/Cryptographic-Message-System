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
	int timeHH();
	int timeMM();
	int timeSS();
private:	



};

