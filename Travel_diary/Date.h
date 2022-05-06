#pragma once
#include <sstream>
#include <cassert>

class Date {
private:
	char year[5];
	char month[3];
	char day[3];
	void vali_date(const char* year, const char* month, const char* day);
public:	
	Date();
	Date(const char* year, const char* month, const char* day);
	Date(const Date& other);
	bool operator <(const Date& other) const;
	bool operator >(const Date& other) const;
	friend std::ostream& operator <<(std::ostream& os, const Date& object);
	friend std::istream& operator >>(std::istream& is,  Date& object);
};