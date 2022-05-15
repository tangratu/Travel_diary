#pragma once
#include <sstream>
#include <cassert>
#include <iostream>
#include "Format.cpp"
class Picture {
private:
	char* name;
	size_t size;	
	Format::type format;
	void check_chars();
public:
	Picture();
	Picture(const char* name1,  Format::type format1);
	~Picture();
	Picture& operator =(const Picture& other);
	friend std::ostream& operator <<(std::ostream& os, const Picture& object);
	friend std::istream& operator >>(std::istream& is, Picture& object);
};
