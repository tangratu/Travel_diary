#include<iostream>
#include "Date.h"






void Date::vali_date(const char* year, const char* month, const char* day)
{
	int year_n = atoi(year);
	int month_n = atoi(month);
	int day_n = atoi(day);

	if (year_n < 1000 || year_n > 9999) {
		assert("Invalid year");
	}
	//look into validation
	switch (month_n) {
	case 1: {
		if (day_n < 1 || day_n>31) { assert("Invalid day"); }
		break;
	}
	case 2: {
		if (year_n % 4 == 0) {
			if (day_n < 1 || day_n > 29) { assert("Invalid day"); }
		}
		else {
			if (day_n < 1 || day_n > 28) { assert("Invalid day"); }
		}
		break;
	}
	case 3: {
		if (day_n < 1 || day_n>31) { assert("Invalid day"); }
		break;
	}
	case 4: {
		if (day_n < 1 || day_n>30) { assert("Invalid day"); }
		break;
	}
	case 5:
	{
		if (day_n < 1 || day_n>31) { assert("Invalid day"); }
		break;
	}
	case 6: {
		if (day_n < 1 || day_n>30) { assert("Invalid day"); }
		break;
	}
	case 7: {
		if (day_n < 1 || day_n>31) { assert("Invalid day"); }
		break;
	}
	case 8: {
		if (day_n < 1 || day_n>31) { assert("Invalid day"); }
		break;
	}
	case 9: {
		if (day_n < 1 || day_n>30) { assert("Invalid day"); }
		break;
	}
	case 10: {
		if (day_n < 1 || day_n>31) { assert("Invalid day"); }
		break;
	}
	case 11: {
		if (day_n < 1 || day_n>30) { assert("Invalid day"); }
		break;
	}
	case 12: {
		if (day_n < 1 || day_n>31) { assert("Invalid day"); }
		break;
	}
	default: {
		assert("Invalid day");
	}
	}
}

Date::Date()
{

}

Date::Date(const char* year, const char* month, const char* day)
{
	
	vali_date(year, month, day);
		strcpy(this->year, year);
		strcpy(this->month, month);
		strcpy(this->day, day);
	
	
}

Date::Date(const Date& other)
{
	strcpy(this->year, other.year);
	strcpy(this->month, other.month);
	strcpy(this->day, other.day);
}

bool Date::operator<(const Date& other) const
{
	int year1 = atoi(this->year);
	int year2 = atoi(other.year);
	int month1 = atoi(this->month);
	int month2 = atoi(other.month);
	int day1 = atoi(this->day);
	int day2 = atoi(other.day);
	return (year1 < year2) || (year1 == year2 && month1 < month2) || (year1 == year2 && month1 == month2 && day1 < day2);
}

bool Date::operator>(const Date& other) const
{
	int year1 = atoi(this->year);
	int year2 = atoi(other.year);
	int month1 = atoi(this->month);
	int month2 = atoi(other.month);
	int day1 = atoi(this->day);
	int day2 = atoi(other.day);
	return (year1 > year2) || (year1 == year2 && month1 > month2) || (year1 == year2 && month1 == month2 && day1 > day2);
}

Date& Date::operator=(const Date& other)
{
	if (this != &other) {
		strcpy(year, other.year);
		strcpy(month, other.month);
		strcpy(day, other.day);
	}
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Date& object)
{
	os << object.year << '-' << object.month << '-' << object.day;
	return os;
}

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
