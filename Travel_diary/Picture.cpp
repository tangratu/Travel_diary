#include "Picture.h"

void Picture::check_chars()
{
	for (size_t i = 0; i < size; i++)
	{
		if (name[i] == ';' || name[i] == ':' || name[i] == ',' || name[i] == '.' || name[i] == '!' || name[i] == ' ') // more checks for invalid characters can be made with the same code.
		{
			throw std::invalid_argument("Invalid characters in name");
		}
	}
}

Picture::Picture()
{
	name = new (std::nothrow) char[2];
	assert(name);
	size = 1;
	format = Format::png;
	strcpy(name, "0");
}

Picture::Picture(const char* name1,  Format::type format1)
{
	size = strlen(name1);
	name = new (std::nothrow) char[size + 1];
	assert(name);	
	format = format1;
	strcpy(name, name1);

}

Picture::~Picture()
{
	delete[] name;
}

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

std::ostream& operator<<(std::ostream& os, const Picture& object)
{
	os << object.name << '.';
	if (object.format == 0) { os << "jpeg"; }
	else {
		os << "png";
	}
	return os;
}

std::istream& operator>>(std::istream& is,  Picture& object)
{
	delete[] object.name;
	char buffer[50];
	
	is.getline(buffer, 50);
	
	object.size = 0;
	while (buffer[object.size] != '.') {
		object.size++;
	}
	object.name = new (std::nothrow) char[object.size + 1];
	assert(object.name);
	strncpy(object.name, buffer, object.size);
	object.name[object.size] = '\0';
	int i = object.size + 1;
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
