#pragma once
#include "Date.h"
#include "Format.cpp"
#include "Picture.h"
#include "User.h"
#include <sstream>
/*!
* A class to contain all the information of an entry in the a user's travel journal. Has fields for the trip's start and end dates
* which are from the date class, a grade in the range of 1-5 and a dynamic array of picture objects.
*/ 
class Journey {
private:
	//! A dynamic array for storing the destination
	char* dest;
	//! Stores the size of the dynamic array for the destination
	size_t dest_s;
	//! A date object for the start date
	Date sdate;
	//! A date object for the end date
	Date edate;
	//! A int object to store the grade
	int grade;
	//! A char array with a fixed size of 500 to store the comment for this entry
	char comment[500];
	//! Dynamic array containing picture object
	Picture* pics;
	//! Stores the size of the dynamic picture array
	size_t pics_s;
public:
	Journey();
	
	Journey( const char* dest1, const Date& sdate1, const Date& edate1, int grade1, const char* comment1, const Picture* pics1,size_t pics1_s);
	Journey( const char* dest1, const Date& sdate1, const Date& edate1, int grade1, const char* comment1, const Picture& pic);
	~Journey();
	friend std::ostream& operator<<(std::ostream& os, const Journey& obj);
	friend std::istream& operator>>(std::istream& is, Journey& obj);
};