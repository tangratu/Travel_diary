#pragma once
#include<sstream>
#include<cassert>
class User {
private:
	char* name;
	size_t name_s;
	char* pass;
	size_t pass_s;
	char* email;
	size_t email_s;
	
public:
	User();
	User(const char* name1, const char* pass1, const char* email1);
	~User();
	friend std::ostream& operator<<(std::ostream& os, const User& object);
	friend std::istream& operator>>(std::istream& is, User& object);
};