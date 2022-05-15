#pragma once
#include "Date.h"
#include "Format.cpp"
#include "Picture.h"
#include "User.h"
#include <sstream>
class Journey {
private:
	
	char* dest;
	size_t dest_s;
	Date sdate;
	Date edate;
	int grade;
	char comment[500];
	Picture* pics;
	size_t pics_s;
public:
	Journey();
	
	Journey( const char* dest1, const Date& sdate1, const Date& edate1, int grade1, const char* comment1, const Picture* pics1,size_t pics1_s);
	Journey( const char* dest1, const Date& sdate1, const Date& edate1, int grade1, const char* comment1, const Picture& pic);
	~Journey();
	friend std::ostream& operator<<(std::ostream& os, const Journey& obj);
	friend std::istream& operator>>(std::istream& is, Journey& obj);
};