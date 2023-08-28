#include "library.h"

Library::Library( std::string _libraryName ) : libraryName( _libraryName ) {
	books = new OrderedList<Book>();
}

Library::~Library() {
}

Book Library::createBook( int _bookCode, std::string _authorName, std::string _authorLastName, std::string _title, int _year ) {
	return Book( _bookCode, _authorName, _authorLastName, _title, _year );
}

bool Library::insertBook( int _bookCode, std::string _authorName, std::string _authorLastName, std::string _title, int _year ) {
	Book bookToAdd = createBook( _bookCode, _authorName, _authorLastName, _title, _year );
	if( books->addElement( bookToAdd ) )
		return true;
	return false;
}

bool Library::deleteBook( int bookCode ) {
	if( books->removeElement( bookCode ) )
		return true;
	return false;
}

int Library::numberOfBooks() {
	return books->getCount();
}

std::string Library::showBook( int codeBookToShow ) {
	Book* bookToShow = books->findElement( codeBookToShow );
	if( bookToShow == nullptr )
		return "Book Not Found";
	return bookToShow->toString();
}

std::string Library::theBooks() {
	return books->toString();
}
