#include "Validator.h"


Validator::Validator()
{
	this->errorExists = true;
}

void Validator::validationBalance(double& inputIalance)
{
	if (!this->errorExists) {
		return;
	}

	std::string input;
	size_t pos = 0;
	double testInput = 0;

	try {

		std::cin >> input;   
		testInput = std::stod(input, &pos);

		if (pos != input.length()){
			throw std::invalid_argument(" ");
		}

		if (testInput < 0) {
			throw std::out_of_range("entered number is less than 0");
		}

		inputIalance = testInput;

	}
	catch(std::invalid_argument& e) {
		std::cerr <<"Error: The program only processes numbers"<< '\n' << '\n';

		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		this->errorExists = false;
	}
	catch (std::out_of_range& e) {
		std::cerr << e.what() << '\n' << '\n';

		std::cin.clear();
		this->errorExists = false;
	}
	
}

void Validator::validationName(std::string& inputName)
{
	if (!this->errorExists) {
		return;
	}

	std::cin >> inputName;

	if (inputName.length() < 4 && inputName.length() > 30) {
		std::cout << "The entered length cannot be less than 4 and more than 30 characters\n";
		this->errorExists = false;
	}

	std::regex pattern("[[:alpha:]]*");

	if (!std::regex_match(inputName, pattern)) {
		std::cout << "Name should be have only letters\n";
		this->errorExists = false;
	}

}

void Validator::validationTimeYearMonthDay(std::pair<std::string, std::string>& userInterval)
{
	if (!errorExists) {
		return;
	}

	std::cout << "Enter year, month, day in view: \\'year-month-day\\'\n";
	std::string yearMonthDay;

	std::regex dateRegex("\\d{4}-\\d{2}-\\d{2}");

	std::cin >> yearMonthDay;

	if (!std::regex_match(yearMonthDay, dateRegex)) {
		std::cout << "Invalid input YMD\m";
		this->errorExists = false;
		return;
	}

	bool checkValid = isValidNumbersInYearMonthDay(yearMonthDay);

	if (!checkValid) {
		return;
	}

	userInterval.first = yearMonthDay;
}

void Validator::validationTimeHourMinuteSecond(std::pair<std::string, std::string>& userInterval)
{
	if (!errorExists) {
		return;
	}

	std::cout << "Enter hour, minute, second in view: \\'hh:mm:ss\\'\n";
	std::regex hourMinuteSecondRegex("\\d{2}:\\d{2}:\\d{2}");
	std::string hourMinuteSecond;

	std::cin >> hourMinuteSecond;

	if (!std::regex_match(hourMinuteSecond, hourMinuteSecondRegex)) {
		std::cout << "Invalid input HMS\m";
		this->errorExists = false;
		return;
	}

	bool checkValid = isValidNumbersInHourMinuteSecond(hourMinuteSecond);

	if (!checkValid) {
		return;
	}

	userInterval.second = hourMinuteSecond;
}

bool Validator::isValidNumbersInYearMonthDay(std::string yearMonthDay)
{
	int year = std::stoi(yearMonthDay.substr(0, 4));
	
	if (!(year >= YearMonthDayInterval::yearMin && year <= YearMonthDayInterval::yearMax)) {
		
		std::cout << "Invalid interval in year\n";
		this->errorExists = false;
		return false;

	}

	int month = std::stoi(yearMonthDay.substr(5, 2));

	if (!(month >= YearMonthDayInterval::monthMin) && month <= YearMonthDayInterval::monthMax) {
		std::cout << "Invalid interval in month\n";
		this->errorExists = false;
		return false;
	}

	int day = std::stoi(yearMonthDay.substr(7, 2));

	if (!(day >= YearMonthDayInterval::dayMin) && day <= YearMonthDayInterval::dayMax) {
		std::cout << "Invalid interval in day\n";
		this->errorExists = false;
		return false;
	}

	return true;
}

bool Validator::isValidNumbersInHourMinuteSecond(std::string ymd)
{
	int hours = std::stoi(ymd.substr(0, 2));

	if (!(hours >= HourMinuteSecondInterval::hourMin && hours <= HourMinuteSecondInterval::hourMax)) {

		std::cout << "Invalid interval in hours\n";
		this->errorExists = false;
		return false;

	}

	int minutes = std::stoi(ymd.substr(3, 2));

	if (!(minutes >= HourMinuteSecondInterval::minuteMin && minutes <= HourMinuteSecondInterval::minuteMax)) {
		
		std::cout << "Invalid interval in minutes\n";
		this->errorExists = false;
		return false;

	}

	int seconds = std::stoi(ymd.substr(6, 2));

	if (!(seconds >= HourMinuteSecondInterval::secondMin && seconds <= HourMinuteSecondInterval::secondMax)) {
		std::cout << "Invalid interval in seconds\n";
		this->errorExists = false;
		return false;
	}

	return true;
}

bool Validator::chekError()
{
	return this->errorExists;
}
