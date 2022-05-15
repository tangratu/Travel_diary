#pragma once
#include<sstream>
#include <iostream>
#include<cassert>
/*!
* A class to store the info of a user. Contains dynamically allocated char arrays for the name, password and email
* and fields to store the size of the arrays. Like the picture class it has a method to validate the user object's name
*/
class User {
private:
	//! Dynamically allocated char array to store the username
	char* name;
	//! Stores the size of the dynamic char array for the name field
	size_t name_s;
	//! Dynamically allocated char array to store the password
	char* pass;
	//! Stores the size of the dynamic char array for the password field
	size_t pass_s;
	//! Dynamically allocated char array to store the email
	char* email;
	//! Stores the size of the dynamic char array for the email field
	size_t email_s;
	//! Checks if the name has invalid characters and throws an exception of it does
	void check_chars();
	
public:
	const char* getName();
	User();
	User(const char* name1, const char* pass1, const char* email1);
	~User();
	User& operator =(const User& other);
	friend std::ostream& operator<<(std::ostream& os, const User& object);
	friend std::istream& operator>>(std::istream& is, User& object);
};