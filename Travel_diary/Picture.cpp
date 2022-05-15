#include "Picture.h"
//! Checks each char in the array to confirm it is not an invalid char
void Picture::check_chars()
{
	for (size_t i = 0; i < size; i++)
	{
		if (name[i] == ';' || name[i] == ':' || name[i] == ',' || name[i] == '.' || name[i] == '!' || name[i] == ' ') //! more checks for invalid characters can be made with the same code.
		{
			throw std::invalid_argument("Invalid characters in name");
		}
	}
}
//! Default constructor for the class so that the dynamic char array can be initialised
Picture::Picture()
{
	name = new (std::nothrow) char[2];
	assert(name);
	size = 1;
	//! Default format is png
	format = Format::png;
	strcpy(name, "0");
}
//! Constructor with parameters
Picture::Picture(const char* name1,  Format::type format1)
{
	size = strlen(name1);
	name = new (std::nothrow) char[size + 1];
	assert(name);	
	format = format1;
	strcpy(name, name1);

}
//!Destructor to dispose of the manually allocated memory
Picture::~Picture()
{
	delete[] name;
}
//! Copies the values of one picture object to another, also handles dynamic memory
Picture& Picture::operator=(const Picture& other)
{
	if (this != &other) {
		delete[] name;
		size = other.size;
		format = other.format;
		name = new (std::nothrow)char[size + 1];
		assert(name);
		strcpy(name, other.name);
	}
	return *this;
}
//! Outputs the picture in the format name.format
std::ostream& operator<<(std::ostream& os, const Picture& object)
{
	os << object.name << '.';
	if (object.format == 0) { os << "jpeg"; }
	else {
		os << "png";
	}
	return os;
}
//! Turns an input of the format name.format into a picture object
std::istream& operator>>(std::istream& is,  Picture& object)
{
	delete[] object.name;
	char buffer[50];
	
	is.getline(buffer, 50);
	
	object.size = 0;
	//! reades until the . to get the size of the name of the picture
	while (buffer[object.size] != '.') {
		object.size++;
	}
	object.name = new (std::nothrow) char[object.size + 1];
	assert(object.name);
	strncpy(object.name, buffer, object.size);
	//! the strncpy method doesn't add a terminating symbol so it has to be done manually
	object.name[object.size] = '\0';
	int i = object.size + 1;
	//! Reads after the . to determine the format and throw an exception if it is invalid
	while (buffer[i+1] != '\0') {
		i++;
	}
	
	if (i - object.size == 4) {
		object.format = Format::jpeg;
	}
	else if(i - object.size == 3) { object.format =Format::png; }
	else {
		throw std::invalid_argument("Invalid format!");
	}
	return is;
}
