#include "User.h"

const char* User::getName()
{
	return this->name;
}

User::User()
{
	name_s = 1;
	pass_s = 1;
	email_s = 1;
	name = new (std::nothrow) char[name_s+1];
	assert(name);
	pass = new (std::nothrow) char[pass_s+1];
	assert(pass);
	email = new (std::nothrow) char[email_s+1];
	assert(email);
	strcpy(name, "0");
	strcpy(pass, "0");
	strcpy(email, "0");
}

User::User(const char* name1, const char* pass1, const char* email1)
{
	name_s = strlen(name1);
	pass_s = strlen(pass1);
	email_s = strlen(email1);
	name = new (std::nothrow) char[name_s + 1];
	assert(name);
	pass = new (std::nothrow) char[pass_s + 1];
	assert(pass);
	email = new (std::nothrow) char[email_s + 1];
	assert(email);
	strcpy(name, name1);
	strcpy(pass, pass1);
	strcpy(email, email1);
}

User::~User()
{
	delete[] name;
	delete[] pass;
	delete[] email;
}

User& User::operator=(const User& other)
{
	if (this != &other) {
		delete[] name,
		delete[] pass;
		delete[] email;
		name_s = other.name_s; pass_s = other.pass_s; email_s = other.email_s;
		name = new (std::nothrow) char[name_s + 1];
		assert(name);
		strcpy(name, other.name);
		pass = new (std::nothrow) char[pass_s + 1];
		assert(pass);
		strcpy(pass, other.pass);
		email = new (std::nothrow) char[email_s + 1];
		assert(email);
		strcpy(email, other.email);
	}
	return *this;
}

std::ostream& operator<<(std::ostream& os, const User& object)
{
	os << object.name << std::endl << object.pass << std::endl << object.email;
	return os;
}

std::istream& operator>>(std::istream& is, User& object)
{
	delete[] object.name;
	delete[] object.pass;
	delete[] object.email;
	char buffer[50];
	std::cout << "Enter username: ";
	is.getline(buffer, 50);
	object.name_s = strlen(buffer);
	object.name = new (std::nothrow) char[object.name_s + 1];
	assert(object.name);
	strcpy(object.name, buffer);
	char buffer1[50];
	std::cout << "Enter password: ";
	is.getline(buffer1, 50);
	object.pass_s = strlen(buffer1);
	object.pass = new (std::nothrow) char[object.pass_s + 1];
	assert(object.pass);
	strcpy(object.pass, buffer1);
	char buffer2[50];
	std::cout << "Enter email: ";
	is.getline(buffer2, 50);
	object.email_s = strlen(buffer2);
	object.email = new (std::nothrow) char[object.email_s + 1];
	assert(object.email);
	strcpy(object.email, buffer2);
	return is;
}
