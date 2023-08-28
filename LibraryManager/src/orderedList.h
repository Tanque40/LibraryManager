#pragma once
#include <string>

template <typename T>
class OrderedList {
private:
	T* ptr;
	int size = 10;
	int count = 0;

public:
	OrderedList();
	OrderedList( T arr[] );
	OrderedList( T arr[], int size );
	~OrderedList();
	int size();
	int count();
	bool addElement( T element );
	bool removeElement( int elementToRemove );
	T findElement( int elementToFind );
	int findElementPosition( int elementToFind );
	void growArraySize();
	std::string toString();
};