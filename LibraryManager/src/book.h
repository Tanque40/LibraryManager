#pragma once
#include <string>

class Book {
private:
	int bookCode;
	std::string authorName;
	std::string authorLastName;
	std::string title;
	int year;
	int timesBorrowed;

public:
	Book();
	inline Book( int _bookCode,
		std::string _authorName,
		std::string _authorLastName,
		std::string _title,
		int _year ) :
		bookCode( _bookCode ),
		authorName( _authorName ),
		authorLastName( _authorLastName ),
		title( _title ),
		year( _year ),
		timesBorrowed( 0 ) {
	}

	inline bool operator < ( Book* otherBook ) {
		return this->getBookCode() < otherBook->getBookCode();
	}
	inline bool operator < ( int bookCode ) {
		return this->getBookCode() < bookCode;
	}
	inline bool operator > ( Book* otherBook ) {
		return this->getBookCode() > otherBook->getBookCode();
	}
	inline bool operator > ( int bookCode ) {
		return this->getBookCode() > bookCode;
	}
	inline bool operator == ( int bookCode ) {
		return this->getBookCode() == bookCode;
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