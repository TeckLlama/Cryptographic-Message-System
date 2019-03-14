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

	std::string getTimeHHMMSS();
	int getTimeHH();
	int getTimeMM();
	int getTimeSS();
private:	



};

