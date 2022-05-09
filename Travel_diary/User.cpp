#include "User.h"

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

std::ostream& operator<<(std::ostream& os, const User& object)
{
	os << object.name;
	return os;
}

std::istream& operator>>(std::istream& is, User& object)
{
	delete[] object.name;
	delete[] object.pass;
	delete[] object.email;
	char buffer[50];
	is.getline(buffer, 50);
	object.name_s = strlen(buffer);
	object.name = new (std::nothrow) char[object.name_s + 1];
	assert(object.name);
	strcpy(object.name, buffer);
	char buffer1[50];
	is.getline(buffer1, 50);
	object.pass_s = strlen(buffer1);
	object.pass = new (std::nothrow) char[object.pass_s + 1];
	assert(object.pass);
	strcpy(object.pass, buffer1);
	char buffer2[50];
	is.getline(buffer2, 50);
	object.email_s = strlen(buffer2);
	object.email = new (std::nothrow) char[object.email_s + 1];
	assert(object.email);
	strcpy(object.email, buffer2);
	return is;
}
