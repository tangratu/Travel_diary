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

Journey::Journey( const char* dest1, const Date& sdate1, const Date& edate1, int grade1, const char* comment1, const Picture* pics1, size_t pics1_s) {
	
	
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



Journey::~Journey()
{
	delete[] dest;
	delete[] pics;
}

std::ostream& operator<<(std::ostream& os, const Journey& obj)
{
	
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
	delete[] obj.dest;
	delete[] obj.pics;
	char buffer1[50];
	std::cout << "Enter destination: ";
	is.getline(buffer1, 50);
	obj.dest_s = strlen(buffer1);
	obj.dest = new(std::nothrow)char[obj.dest_s + 1];
	assert(obj.dest);
	strcpy(obj.dest, buffer1);
	std::cout << "Enter start date: ";
	is >> obj.sdate;
	std::cout << "Enter end date: ";
	is >> obj.edate;
	if (obj.sdate > obj.edate) {
		throw std::invalid_argument("Start date is after end date!");
	}
	std::cout << "Enter grade: ";
	is >> obj.grade;
	is.ignore();
	if (obj.grade < 1 || obj.grade >5) {
		throw std::invalid_argument("Invalid grade score!");
	}
	char buffer[500];
	std::cout << "Type comment: ";
	is.getline(buffer, 500);
	strcpy(obj.comment, buffer);
	std::cout << "Enter number of pictures: ";
	is >> obj.pics_s;
	is.ignore();
	obj.pics = new (std::nothrow)Picture[obj.pics_s];
	assert(obj.pics);
	std::cout << "Enter names of pictures one per line:"<<std::endl;
	for (size_t i = 0; i < obj.pics_s; i++)
	{
		is >> obj.pics[i];
	}
	return is;
}
