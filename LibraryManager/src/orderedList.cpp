#include "orderedList.h"

template<typename T>
OrderedList<T>::OrderedList() {
	ptr = new T[ size ];
}

template<typename T>
OrderedList<T>::OrderedList( T arr[] ) {
	ptr = new T[ size ];
	for( int i = 0; i < count; i++ )
		ptr[ i ] = arr[ i ];
}

template<typename T>
OrderedList<T>::OrderedList( T arr[], int size ) {
	this->size = size;
	this->count = size;
	OrderedList( arr );
}

template<typename T>
OrderedList<T>::~OrderedList() {
	ptr = NULL;
}

template<typename T>
bool OrderedList<T>::addElement( T element ) {
	if( count + 1 >= size )
		this->growArraySize();

	int positionToAsign = 0;
	if( count == 0 ) {
		ptr[ positionToAsign ] = element;
		count++;
		return true;
	} else {

		bool positionFounded = false;
		int left = 0;
		int right = count;
		while( !positionFounded && positionToAsign < count ) {
			positionToAsign = l + ( r - l ) / 2;
			if( positionToAsign > 0 && positionToAsign < count - 1 ) {
				if( element > ptr[ positionToAsign - 1 ] && element > ptr[ positionToAsign - 1 ] )
					positionFounded = true;
				else {
					if( element > ptr[ positionToAsign ] )
						left = positionToAsign + 1;
					else
						right = positionToAsign - 1
				}
			} else if( positionToAsign == count - 1 ) {
				positionFounded = true
					if( element > ptr[ positionToAsign ] ) {
						positionToAsign++;
						ptr[ positionToAsign ] = element;
						count++;
						return true;
					}
			}
		}

		count++;
		for( int i = positionToAsign; i < count; i++ )
			ptr[ ( count - 1 ) - i - positionToAsign ] = ptr[ ( count - 1 ) - i - positionToAsign - 1 ];

		ptr[ positionToAsign ] = element;

		return true;
	}

	return false;
}

template<typename T>
int OrderedList<T>::size() {
	return size;
}

template<typename T>
int OrderedList<T>::count() {
	return count;
}

template<typename T>
bool OrderedList<T>::removeElement( int elementToRemove ) {
	int indexToRemove = findElementPosition( elementToRemove );
	if( indexToRemove >= 0 ) {
		if( indexToRemove == count - 1 )
			ptr[ indexToRemove ] = NULL;
		else
			for( int i = indexToRemove; i < count - 1; i++ )
				ptr[ i ] = ptr[ i + 1 ];
		count--;
		return true;
	}
	return false;
}

template<typename T>
T OrderedList<T>::findElement( int elementToFind ) {
	int index = findElementPosition( elementToFind );
	if( index >= 0 )
		return ptr[ index ];
	return NULL;
}

template<typename T>
int OrderedList<T>::findElementPosition( int elementToFind ) {
	int left = 0;
	int right = count;

	while( left <= right ) {
		int middle = left + ( right - left ) / 2;

		if( ptr[ middle ] == elementToFind )
			return middle;

		if( ptr[ middle ] < elementToFind )
			left = middle + 1;

		else
			right = middle - 1;
	}
	return -1;
}

template<typename T>
void OrderedList<T>::growArraySize() {
	size = this->size * 2;
	T* temp = new T[ size ];
	for( int i = 0; i < count; i++ ) {
		temp[ i ] = ptr[ i ];
	}
	ptr = temp;
}

template<typename T>
std::string OrderedList<T>::toString() {
	std::string response = "";

	if( size ) {
		for( int i = 0; i < size; i++ ) {
			response += ptr[ i ].toString() + "\n--------------------\n";
		}
		return response;
	} else {
		return "No books to show";
	}
}