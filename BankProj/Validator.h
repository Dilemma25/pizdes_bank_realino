#pragma once
#include<stdexcept> 
#include<limits>
#include<iostream>
#include<string>
#include <regex>

class Validator {
	bool errorExists;

	enum YearMonthDayInterval {
		yearMin = 2023,
		yearMax = 2030,

		monthMin = 1,
		monthMax = 12,

		dayMin = 1,
		dayMax = 31
	};

	enum HourMinuteSecondInterval {
		hourMin = 0,
		hourMax = 23,

		minuteMin = 0,
		minuteMax = 59,

		secondMin = 0,
		secondMax = 59
	};

	bool isValidNumbersInYearMonthDay(std::string yearMonthDat);

	bool isValidNumbersInHourMinuteSecond(std::string ymd);

public:
	Validator();
	void validationBalance(double& inputBalance);
	void validationName(std::string& inputString);

	void validationTimeYearMonthDay(std::pair<std::string, std::string>& userInterval);
	void validationTimeHourMinuteSecond(std::pair<std::string, std::string>& userInterval);

	bool chekError();
	

};