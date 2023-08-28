#include "book.h"

Book::Book() {
}

int Book::getBookCode() {
	return bookCode;
}

std::string Book::getAuthorName() {
	return authorName;
}

std::string Book::getAuthorLastName() {
	return authorLastName;
}

std::string Book::getTitle() {
	return title;
}

int Book::getYear() {
	return year;
}

int Book::getTimesBorrowed() {
	return timesBorrowed;
}

void Book::bookBorrowed() {
	timesBorrowed++;
}

void Book::bookReturned() {
	timesBorrowed--;
}

std::string Book::toString() {
	return "Book Code: " + this->getBookCode() +
		std::string( "\nTitle: " ) + this->getTitle() +
		std::string( "\nAuthor Name: " ) + this->getAuthorName() +
		std::string( "\nAuthor Lastname: " ) + this->getAuthorLastName() +
		std::string( "\nYear: " ) + std::to_string( this->getYear() ) +
		std::string( "\nTimes Borrowed: " ) + std::to_string( this->getTimesBorrowed() );
}
