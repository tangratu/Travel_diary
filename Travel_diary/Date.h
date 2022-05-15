#pragma once
#include <sstream>
#include <cassert>
#include <iostream>
/*!
	* This class handles dates and includes overwrites of the comparison operators > and <
	* and the stream operators >> and <<. Dates have a year , month and day and are in the YYYY-MM-DD format.
	* Not following the format or inputting invalid values for the year, month or day will result in a thrown exception.
	*/
class Date {
	
private:
	/*! \brief A char array that stores the year of the date.
	* 
	* The array is of a fixed size of 5 because years are in the YYYY format and end with a termination symbol.
	*/
	char year[5];
	/*! \brief A char array that stores the month of the date.
	*
	* The array is of a fixed size of 3 because months are in the MM format and end with a termination symbol.
	*/
	char month[3];
	/*! \brief A char array that stores the day of the date.
	*
	* The array is of a fixed size of 3 because days are in the DD format and end with a termination symbol.
	*/
	char day[3];
	
	void vali_date(const char* year, const char* month, const char* day);
public:	
	Date();
	Date(const char* year, const char* month, const char* day);
	Date(const Date& other);
	bool operator <(const Date& other) const;
	bool operator >(const Date& other) const;
	Date& operator =(const Date& other);
	friend std::ostream& operator <<(std::ostream& os, const Date& object);
	friend std::istream& operator >>(std::istream& is,  Date& object);
};