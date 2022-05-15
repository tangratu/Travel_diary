#include "Journey.h"
#include <iostream>
#include <fstream>
/*!
* This class handles the execution of the travel journey's functionalities.
* They are: creating new users with a username, password and email, login in as existing users with a username and password,
* creating new entries into each user's travel journal and the search function.
* The search function takes a destination entered by the user and checks all other users's databases for entries
* which have the same destination. It then prints the information for each one in a special format.
*/
 class Travel_Journal {
	 //! A method to change which database is accesed
	 /*!
	 * This static method uses a reference to a dynamic char array in which we store the name of a user's database to
	 * change that array to a different one containing the name of another user's database. The name of the new user is given via the
	 * uname parameter.
	 */
	static void change_fname(char* (&fname), const char* uname) {
		int i = strlen(uname);
		fname = new(std::nothrow)char[i + 4];
		strcpy(fname, uname);
		strcat(fname, ".db");
	}
 public:
	 //! This method handles all of the class's listed functionalities
 static	int Open_Journal() {
	 //! A large buffer for reading information from the users' databases;
		char input[500];
		//! An ofstream object for outputting information to the files
		std::ofstream ofs;
		//! The first ifstream object is used for reading from the list of users
		std::ifstream ifs;
		//! This second ifstream object is used for reading from a user's database
		std::ifstream ifs_diary;
		
		std::cout << "Type L to login as an existing user or R to register a new user" << std::endl;
	retrycommand:
		//! The try catch checks if the command is valid and if it is not it has to be entered again
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
		//! the fname parameter is where we will store the name of the database we want to access
			char* fname = nullptr;
			//! This parameter will contain the user we are logged in as
			User currentuser;
			//! Writes the information of a new user into the user list database
			if (input[0] == 'R') {	
			retryname:
				//! Watches for the invalid chars in name exception
				try {
					
					std::cin >> currentuser;
					ofs.open("users.db", std::ios::app);
					if (!ofs.is_open()) { std::cout << "Problem opening users.db."; return 1; }
					ofs << currentuser << std::endl;
					ofs.close();
					change_fname(fname, currentuser.getName());
				}
				catch (const std::invalid_argument& e) {
					std::cerr << e.what();
					goto retryname;
				}



			}
		
		//! Logs in as an existing user
		else {
			retrylogin:
			std::cout << "Enter username: ";
			char uname[50];
			std::cin.getline(uname, 50);
			char upass[50];
			std::cout << "Enter password: ";
			std::cin.getline(upass, 50);
		
			ifs.open("users.db");
			//! Always check if the file opening was successful
			if (!ifs.is_open()) { std::cout << "Problem opening users.db."; return 1; }
			//! a bool flag to keep track of if we have found a user with the entered username or if we haven't
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
							//! If the password is wrong the login can be retried
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
					//! If there is no user with the entered username the program exits
					throw std::invalid_argument("No such user exists!");
				}
			}
			catch (const std::invalid_argument& e) {
				std::cerr << e.what();
				ifs.close();
				return 0;
			}

		}
			
		std::cout << "Type S to begin searching for a travel destinations, type C to create a travel diary listing or E to end program." << std::endl;
	retrycommand2:
		try {
			std::cin.getline(input, 500);
			//! If the command is invalid it can be entered again
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
				//! This case handles the creation of new entries in a user's travel journal
			case 'C': {
			reenter_journal:
				try {
					
					Journey inp;
					//! If there is an error while entering the information entry will be retried
					std::cin >> inp;
					//! Write the information to the user's database
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
					//! This case handles the search function
			case 'S': {
				std::cout << "Enter destination to search: ";
				char dest[60];
				std::cin.getline(dest, 60);
				ifs.open("users.db");
				if (!ifs.is_open()) { std::cout << "Problem opening users.db."; return 1; }
				//! This while goes through the list of users
				while (!ifs.eof()) {
					char temp_n[50];
					ifs.getline(temp_n, 50);
					//! This if statement ensure we read only from other users' databases
					if (strcmp(currentuser.getName(), temp_n) != 0) {
						delete[] fname;
						char temp_p[50];
						char temp_e[50];
						ifs.getline(temp_p, 50);
						ifs.getline(temp_e, 50);
						//! Used to store the user whose database we are currently looking through
						User tempuser(temp_n, temp_p, temp_e);
						//! Scope to the database belonging to the temporary user
						change_fname(fname, tempuser.getName());
						ifs_diary.open(fname);
						//! Read through each destination in the user's database
						while (!ifs_diary.eof()) {
							ifs_diary.getline(input, 500);
							if (strcmp(dest, input) == 0) {
								//! The special format in which the information is printed on the console
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
							//! If this is not the searched destination we skip through the lines containing it's info
							else {
								for (size_t i = 0; i < 4; i++)
								{
									ifs_diary.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
								}
								//! Read how many lines of picture there are
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
					//! If this is our user skip though the two lines after it containing it's password and email
					else {
						ifs.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						ifs.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					}

				}
				//! Scope back to the current user's database
				ifs.close();
				delete[] fname;
				change_fname(fname, currentuser.getName());

			}




			}
			//! Commands are repeated until the command for end E is given
			std::cout << "Operation complete, next command: ";
			std::cin >> input[0];
			std::cin.ignore();
		}
		//! Dispose of dynamic memory
		delete[] fname;
		return 0;
	}
};