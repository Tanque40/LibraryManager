#pragma once
#include <string>

class Book{
private:
	int bookCode;
	std::string authorName;
	std::string authorLastName;
	std::string title;
	int year;
	int timesBorrowed;

public:
	Book( int _bookCode,
		std::string _authorName,
		std::string _authorLastName,
		std::string _title,
		int _year,
		int _timesBorrowed ) :
		bookCode( _bookCode ),
		authorName( _authorName ),
		authorLastName( _authorLastName ),
		title( _title ),
		year( _year ),
		timesBorrowed( 0 ){
	}
	int getBookCode();
	std::string getAuthorName();
	std::string getAuthorLastName();
	std::string getTitle();
	int getYear();
	int getTimesBorrowed();
	void bookBorrowed();
	void bookReturned();
	std::string toString();
};