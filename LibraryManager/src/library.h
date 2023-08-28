#pragma once

#include <string>

#include "book.h"
#include "orderedList.h"


class Library{
private:
	std::string libraryName;
	OrderedList<Book> books;
public:

};