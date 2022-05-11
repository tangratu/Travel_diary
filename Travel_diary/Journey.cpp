#include "Journey.h"

Journey::Journey() : dest_s(1), grade(1), pics_s(1)
{
	
	dest = new (std::nothrow) char[dest_s + 1];
	assert(dest);
	strcpy(dest, "0");	
	strcpy(comment, "0");
	pics = new (std::nothrow) Picture[pics_s];
	assert(pics);
}
Journey::Journey(const User& user1, const char* dest1, const Date& sdate1, const Date& edate1, int grade1, const char* comment1, const Picture* pics1, size_t pics1_s) {
	
	user = user1;
	dest_s = strlen(dest1);
	dest = new (std::nothrow)char[dest_s + 1];
	assert(dest);
	strcpy(dest, dest1);
	sdate = sdate1;
	edate = edate1;
	grade = grade1;
	strcpy(comment, comment1);
	pics_s = pics1_s;
	pics = new (std::nothrow)Picture[pics_s];
	assert(pics);
	for (size_t i = 0; i < pics_s; i++)
	{
		pics[i] = pics1[i];
	}
}

Journey::Journey(const User& user1, const char* dest1, const Date& sdate1, const Date& edate1, int grade1, const char* comment1, const Picture& pic) : pics_s(1)
{
	
	user = user1;
	dest_s = strlen(dest1);
	dest = new (std::nothrow)char[dest_s + 1];
	assert(dest);
	strcpy(dest, dest1);
	sdate = sdate1;
	edate = edate1;
	grade = grade1;
	strcpy(comment, comment1);
	pics = new (std::nothrow) Picture[pics_s];
	assert(pics);
	pics[0] = pic;
}

Journey::~Journey()
{
	delete[] dest;
	delete[] pics;
}

std::ostream& operator<<(std::ostream& os, const Journey& obj)
{
	os << obj.user<<std::endl;
	os << obj.dest << std::endl;
	os<<obj.sdate << std::endl;
	os<<obj.edate << std::endl;
	os<<obj.grade << std::endl;
	os<<obj.comment << std::endl;
	os<<obj.pics_s << std::endl;
	for (size_t i = 0; i < obj.pics_s; i++)
	{
		os<<obj.pics[i] << std::endl;
	}
	return os;
}

std::istream& operator>>(std::istream& is, Journey& obj)
{
	is >> obj.user;
	char buffer1[50];
	is.getline(buffer1, 50);
	obj.dest_s = strlen(buffer1);
	obj.dest = new(std::nothrow)char[obj.dest_s + 1];
	assert(obj.dest);
	strcpy(obj.dest, buffer1);
	is >> obj.sdate >> obj.edate >> obj.grade;
	is.ignore();
	char buffer[500];
	is.getline(buffer, 500);
	strcpy(obj.comment, buffer);
	is >> obj.pics_s;
	is.ignore();
	obj.pics = new (std::nothrow)Picture[obj.pics_s];
	assert(obj.pics);
	for (size_t i = 0; i < obj.pics_s; i++)
	{
		is >> obj.pics[i];
	}
	return is;
}
