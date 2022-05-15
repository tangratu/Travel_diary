#include<iostream>
#include "Date.h"





//! This method checks if the a date is valid and takes it's year, month and day as arguements
void Date::vali_date(const char* year, const char* month, const char* day)
{
	//! This code checks if the date follows the format YYYY-MM-DD by seeing if the arrays have the correct amount of characters
	if (strlen(year) != 4 || strlen(month) != 2 || strlen(day) != 2) {
		//! An exception is thrown if the format is incorrect
		throw std::invalid_argument("Invalid format!");
	}
	//! Converts the year to an integer
	int year_n = atoi(year);
	//! Converts the month to an integer
	int month_n = atoi(month);
	//! Converts the day to an integer
	int day_n = atoi(day);
	//! Checks if the year is in the correct value range and throws and exception if it is not
	if (year_n < 0 || year_n > 9999) {
		throw std::invalid_argument("Invalid year!");;
	}
	
	/*!
	* The switch statement checks the value of the month so that it can correctly validate the value of the day based on the month
	* If the month does not go into any of the cases which are for numbers 1 to 12 it will go into the default case which throws an exception for an invalid month
	* The value of the day is checked based on the month with February or case 2 having and extra if statement to check if it is a leap year or not
	*/
		switch (month_n) {
		case 1: {
			if (day_n < 1 || day_n>31) { throw std::invalid_argument("Invalid day!"); }
			break;
		}
		case 2: {
			if (year_n % 4 == 0) {
				if (day_n < 1 || day_n > 29) { throw std::invalid_argument("Invalid day!"); }
			}
			else {
				if (day_n < 1 || day_n > 28) { throw std::invalid_argument("Invalid day!"); }
			}
			break;
		}
		case 3: {
			if (day_n < 1 || day_n>31) { throw std::invalid_argument("Invalid day!"); }
			break;
		}
		case 4: {
			if (day_n < 1 || day_n>30) { throw std::invalid_argument("Invalid day!"); }
			break;
		}
		case 5:
		{
			if (day_n < 1 || day_n>31) { throw std::invalid_argument("Invalid day!"); }
			break;
		}
		case 6: {
			if (day_n < 1 || day_n>30) { throw std::invalid_argument("Invalid day!"); }
			break;
		}
		case 7: {
			if (day_n < 1 || day_n>31) { throw std::invalid_argument("Invalid day!"); }
			break;
		}
		case 8: {
			if (day_n < 1 || day_n>31) { throw std::invalid_argument("Invalid day!"); }
			break;
		}
		case 9: {
			if (day_n < 1 || day_n>30) { throw std::invalid_argument("Invalid day!"); }
			break;
		}
		case 10: {
			if (day_n < 1 || day_n>31) { throw std::invalid_argument("Invalid day!"); }
			break;
		}
		case 11: {
			if (day_n < 1 || day_n>30) { throw std::invalid_argument("Invalid day!"); }
			break;
		}
		case 12: {
			if (day_n < 1 || day_n>31) { throw std::invalid_argument("Invalid day!"); }
			break;
		}
		default: {
			throw std::invalid_argument("Invalid month!");
		}
		}
	
	
}
//! Default constructor for date is left empty as it has no dynamically allocated arrays to be initialised
Date::Date()
{

}
//! Constructor for date with parameters for year, month and day, also validates
Date::Date(const char* year, const char* month, const char* day)
{
	
	vali_date(year, month, day);
		strcpy(this->year, year);
		strcpy(this->month, month);
		strcpy(this->day, day);
	
	
}


//! comparison operator < which return true if the date on the left is before the one on the right
bool Date::operator<(const Date& other) const
{
	int year1 = atoi(this->year);
	int year2 = atoi(other.year);
	int month1 = atoi(this->month);
	int month2 = atoi(other.month);
	int day1 = atoi(this->day);
	int day2 = atoi(other.day);
	//! compares the int values of the year, month and day to determine the result
	return (year1 < year2) || (year1 == year2 && month1 < month2) || (year1 == year2 && month1 == month2 && day1 < day2);
}
//! comparison operator > which return true if the date on the left is after the one on the right
bool Date::operator>(const Date& other) const
{
	int year1 = atoi(this->year);
	int year2 = atoi(other.year);
	int month1 = atoi(this->month);
	int month2 = atoi(other.month);
	int day1 = atoi(this->day);
	int day2 = atoi(other.day);
	//! compares the int values of the year, month and day to determine the result
	return (year1 > year2) || (year1 == year2 && month1 > month2) || (year1 == year2 && month1 == month2 && day1 > day2);
}
//! Copies the year, month and day of one date to another
Date& Date::operator=(const Date& other)
{
	if (this != &other) {
		strcpy(year, other.year);
		strcpy(month, other.month);
		strcpy(day, other.day);
	}
	return *this;
}
//! Outputs the date in the format YYYY-MM-DD
std::ostream& operator<<(std::ostream& os, const Date& object)
{
	os << object.year << '-' << object.month << '-' << object.day;
	return os;
}
//! Takes an input in the format YYYY-MM-DD and turns in into a date object, also validates input
std::istream& operator>>(std::istream& is, Date& object)
{
	char buffer[50];
	
	is.getline(buffer, 50);
	int i = 0;	
	while (buffer[i] != '-') {
		
		object.year[i] = buffer[i];
		i++;		
	}
	object.year[i] = '\0';
	i++;	
	while(buffer[i] != '-') {
		object.month[i-5] = buffer[i];
		i++;
	}
	object.month[i - 5] = '\0';
	i++;	
	while (buffer[i] != '\0') {
		object.day[i - 8] = buffer[i];
		i++;
	}
	object.day[i - 8] = '\0';
	object.vali_date(object.year, object.month, object.day);
	return is;
}
