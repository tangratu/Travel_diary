#pragma once
#include <sstream>
#include <cassert>
#include <iostream>
#include "Format.cpp"
/*! A class for handling pictures. Has fields for the name of the picture, the size of the name and the format
* Also contains a method to check if the name contains invalid characters.
*/
class Picture {
private:
	//! Dynamically allocated char array to store the picture name
	char* name;
	//! Stores the size of the dynamic char array
	size_t size;
	//! Stores the format of the image which is displayed with a . after the image
	Format::type format;
	//! Checks if the name has invalid characters and throws an exception of it does
	void check_chars();
public:
	Picture();
	Picture(const char* name1,  Format::type format1);
	~Picture();
	Picture& operator =(const Picture& other);
	friend std::ostream& operator <<(std::ostream& os, const Picture& object);
	friend std::istream& operator >>(std::istream& is, Picture& object);
};
