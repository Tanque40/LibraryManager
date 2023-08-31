#include <stdlib.h>
#include <iostream>
#include <string>
#include "library.h"
#include <conio.h>

bool askForNewBook( Library* myLabrary );
bool askForDeleteBook( Library* myLabrary );
std::string askForBookToShow( Library* myLabrary );

int main() {
	Library myLibrary( "FMLS Library" );
	unsigned int selectedOption = 9, defaults;
	while( selectedOption ) {
		system( "cls" );
		switch( selectedOption ) {
			case 1:
				if( askForNewBook( &myLibrary ) )
					std::cout << "Book Added Succesfully" << std::endl;
				else
					std::cout << "Error on add book" << std::endl;
				selectedOption = 9;
				break;

			case 2:
				if( askForDeleteBook( &myLibrary ) )
					std::cout << "Book Delete Succesfully" << std::endl;
				else
					std::cout << "Error on delete book. \nMaybe bad code?" << std::endl;
				selectedOption = 9;
				break;

			case 3:
				std::cout << "The number of Books is: " << myLibrary.numberOfBooks() << std::endl;
				selectedOption = 9;
				break;

			case 4:
				std::cout << askForBookToShow( &myLibrary ) << std::endl;
				selectedOption = 9;

				break;

			case 5:
				std::cout << myLibrary.theBooks() << std::endl;
				selectedOption = 9;
				break;

			default:
				std::cout << "##########################################" << std::endl;
				std::cout << "############## " << myLibrary.getLibraryName() << " ##############" << std::endl;
				std::cout << "############### Main Menu ################" << std::endl;
				std::cout << "##########################################" << std::endl;
				std::cout << "1. Add Book" << std::endl;
				std::cout << "2. Delete Book" << std::endl;
				std::cout << "3. Number of Books" << std::endl;
				std::cout << "4. Show Book" << std::endl;
				std::cout << "5. Show all Books" << std::endl;
				std::cout << "0. Exit" << std::endl;
				std::cout << "Type a number option: ";
				std::cin >> selectedOption;
				break;
		}

		if( selectedOption == 9 && selectedOption != 0 ) {
			std::cout << "Press enter to continue..." << std::endl;
			defaults = _getch();
		}

	}

	return 0;
}

bool askForNewBook( Library* myLabrary ) {
	int bookCode, year;
	std::string authorName, authorLastName;

	std::string title;
	std::cout << "############## Add New Book Option ##############" << std::endl;
	std::cout << "Type book code: ";
	std::cin >> bookCode;
	std::cout << "Type book title: ";
	std::cin >> title;
	std::cout << "Type book author name: ";
	std::cin >> authorName;
	std::cout << "Type book author last name: ";
	std::cin >> authorLastName;
	std::cout << "Type book year: ";
	std::cin >> year;

	return myLabrary->insertBook( bookCode, authorName, authorLastName, title, year );
}

bool askForDeleteBook( Library* myLabrary ) {
	int bookCode;
	std::cout << "############## Delete Book Option ##############" << std::endl;
	std::cout << "Enter book code of the book to delete: ";
	std::cin >> bookCode;

	return myLabrary->deleteBook( bookCode );
}

std::string askForBookToShow( Library* myLabrary ) {
	int bookCode;
	std::cout << "############## Show Book Option ##############" << std::endl;
	std::cout << "Enter book code of the book to show: ";
	std::cin >> bookCode;

	return myLabrary->showBook( bookCode );
}