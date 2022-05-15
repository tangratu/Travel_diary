#include "Journey.h"
#include <iostream>
#include <fstream>
 class Travel_Journal {
	static void change_fname(char* (&fname), const char* uname) {
		int i = strlen(uname);
		fname = new(std::nothrow)char[i + 4];
		strcpy(fname, uname);
		strcat(fname, ".db");
	}
 public:
 static	int Open_Journal() {
		char input[500];
		std::ofstream ofs;
		std::ifstream ifs;
		std::ifstream ifs_diary;
		
		std::cout << "Type L to login as an existing user or R to register a new user" << std::endl;
	retrycommand:
		try {
			std::cin.getline(input, 500);
			if (strlen(input) != 1 || (input[0] != 'L' && input[0] != 'R')) {
				throw std::invalid_argument("Invalid command");
			}
		}
		catch (const std::invalid_argument& e) {
			std::cerr << e.what()<<std::endl;
			goto retrycommand;
		}		
			char* fname = nullptr;
			User currentuser;
			if (input[0] == 'R') {	
			retryname:
				try {
					
					std::cin >> currentuser;
					ofs.open("users.db", std::ios::app);
					if (!ofs.is_open()) { std::cout << "Problem opening users.txt."; return 1; }
					ofs << currentuser << std::endl;
					ofs.close();
					change_fname(fname, currentuser.getName());
				}
				catch (const std::invalid_argument& e) {
					std::cerr << e.what();
					goto retryname;
				}



			}
		
		
		else {
			std::cout << "Enter username: ";
			char uname[50];
			std::cin.getline(uname, 50);
			char upass[50];
			std::cout << "Enter password: ";
			std::cin.getline(upass, 50);
		retrylogin:
			ifs.open("users.db");
			if (!ifs.is_open()) { std::cout << "Problem opening users.txt."; return 1; }
			bool found_user = false;
			while (!ifs.eof() ^ found_user) {
				try {

					char temp[50];
					ifs.getline(temp, 50);
					if (strcmp(uname, temp) == 0) {
						ifs.getline(temp, 50);
						if (strcmp(upass, temp) == 0) {
							char umail[60];
							ifs.getline(umail, 60);
							ifs.close();
							currentuser = User(uname, upass, umail);
							found_user = true;
							change_fname(fname, currentuser.getName());
						}
						else {
							throw std::invalid_argument("Wrong password!");
						}
					}
					else {
						//the code for the ignore func is not mine and was taken from https://stackoverflow.com/questions/2581794/skip-lines-in-stdistream
						ifs.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						ifs.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					}
				}
				catch (const std::invalid_argument& e) {
					std::cerr << e.what();
					ifs.close();
					goto retrylogin;
				}
			}

			try {
				if (!found_user)
				{
					throw std::invalid_argument("No such user exists!");
				}
			}
			catch (const std::invalid_argument& e) {
				std::cerr << e.what();
				ifs.close();
				return 0;
			}

		}
			retrycommand2:
		std::cout << "Type S to begin searching for a travel destinations, type C to create a travel diary listing or E to end program." << std::endl;
		try {
			std::cin.getline(input, 500);
			if (strlen(input) != 1 || (input[0] != 'S' && input[0] != 'C' && input[0] != 'E')) {
				throw std::invalid_argument("Invalid command");
			}
		}
		catch (const std::invalid_argument& e) {
			std::cerr << e.what();
			goto retrycommand2;
		}
		while (input[0] != 'E') {
			switch (input[0]) {
			case 'C': {
			reenter_journal:
				try {
					
					Journey inp;
					std::cin >> inp;
					ofs.open(fname, std::ios::app);
					ofs << inp;
					ofs.close();
					break;
				}
				catch (const std::invalid_argument& e) {
					std::cerr << e.what();
					
					goto reenter_journal;
				}
			}
			case 'S': {
				std::cout << "Enter destination to search: ";
				char dest[60];
				std::cin.getline(dest, 60);
				ifs.open("users.db");
				while (!ifs.eof()) {
					char temp_n[50];
					ifs.getline(temp_n, 50);
					if (strcmp(currentuser.getName(), temp_n) != 0) {
						delete[] fname;
						char temp_p[50];
						char temp_e[50];
						ifs.getline(temp_p, 50);
						ifs.getline(temp_e, 50);
						User tempuser(temp_n, temp_p, temp_e);
						change_fname(fname, tempuser.getName());
						ifs_diary.open(fname);
						while (!ifs_diary.eof()) {
							ifs_diary.getline(input, 500);
							if (strcmp(dest, input) == 0) {
								std::cout << "From user " << tempuser.getName() << ":" << std::endl << "Trip began on ";
								Date temp_date;
								ifs_diary >> temp_date;
								std::cout << temp_date << std::endl << "Trip ended on ";
								ifs_diary >> temp_date;
								std::cout << temp_date << std::endl << "User graded the trip ";
								ifs_diary.getline(input, 500);
								std::cout << input << "/5" << std::endl << "User wrote:" << std::endl;
								ifs_diary.getline(input, 500);
								std::cout << input << std::endl << "Attached photos:" << std::endl;
								int b;
								ifs_diary.getline(input, 500);
								b = atoi(input);
								for (size_t i = 0; i < b; i++)
								{
									Picture temp_pic;
									ifs_diary >> temp_pic;
									std::cout << temp_pic << std::endl;
								}
								std::cout << std::endl;
							}
							else {
								for (size_t i = 0; i < 4; i++)
								{
									ifs_diary.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
								}
								int b;
								ifs_diary.getline(input, 500);
								b = atoi(input);
								for (size_t i = 0; i < b; i++)
								{
									ifs_diary.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
								}
							}
						}
						ifs_diary.close();

					}
					else {
						ifs.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						ifs.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					}

				}
				ifs.close();
				delete[] fname;
				change_fname(fname, currentuser.getName());

			}




			}
			std::cout << "Operation complete, next command: ";
			std::cin >> input[0];
			std::cin.ignore();
		}
		delete[] fname;
		return 0;
	}
};