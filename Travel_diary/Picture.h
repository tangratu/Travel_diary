#pragma once
#include <sstream>
#include <cassert>
#include "Format.cpp"
class Picture {
private:
	char* name;
	size_t size;	
	Format::type format;
public:
	Picture();
	Picture(const char* name1,  Format::type format1);
	~Picture();
	friend std::ostream& operator <<(std::ostream& os, const Picture& object);
	friend std::istream& operator >>(std::istream& is, Picture& object);
};