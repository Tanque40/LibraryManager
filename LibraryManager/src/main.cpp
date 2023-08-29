#include <iostream>

#include "library.h"

int main() {
	Library myLibrary( "FMLS Library" );
	unsigned int selectedOption = 1;
	while( selectedOption ) {
		switch( selectedOption ) {
			case 1:
				std::cout << "##########################################" << std::endl;
				std::cout << "############## " << myLibrary.getLibraryName() << " ##############" << std::endl;
				std::cout << "############### Main Menu ################" << std::endl;
				std::cout << "##########################################" << std::endl;
				std::cin >> selectedOption;
				break;

			default:
				break;
		}

	}


	std::cout << myLibrary.theBooks().c_str();



	return 0;
}