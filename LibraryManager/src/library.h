#pragma once

#include <string>

#include "book.h"
#include "orderedList.h"


class Library {
private:
	std::string libraryName;
	OrderedList<Book> books;
public:
	Library( std::string _libraryName );
	Book createBook( int _bookCode,
		std::string _authorName,
		std::string _authorLastName,
		std::string _title,
		int _year );
	bool insertBook( int _bookCode,
		std::string _authorName,
		std::string _authorLastName,
		std::string _title,
		int _year );
	bool deleteBook( int bookCode );
	int numberOfBooks();
	std::string showBook( int codeBookToShow );
	std::string theBooks();
};