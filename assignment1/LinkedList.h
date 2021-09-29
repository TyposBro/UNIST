// CSE221 Assignment 1

#ifndef LinkedList_h
#define LinkedList_h

#include <typeinfo>
#include <iostream>

template <typename Type>
class LinkedList
{
public:
	// Constructor
	LinkedList();

	// Destructor
	~LinkedList();

	// Get the value located at index
	Type Get(const int index);

	// Add val at head
	void AddAtHead(const Type& val);

	// Add val at index
	void AddAtIndex(const int index, const Type& val);

	// Delete an element located at index
	void DeleteAtIndex(const int index);

	// Delete val in linked list
	void DeleteValue(const Type& val);

	// Move the first element of val to head
	void MoveToHead(const Type& val);

	// Rotate the linked list right by steps times
	void Rotate(const int steps);

	// Reduce value that repeats multiple times
	void Reduce();

	// Reverse at every k number of nodes at a time
	void K_Reverse(const int k);

	// Sort even and odd numbers separately then append
	void EvenOddSeparateSort();

	// Return the number of elements in the linked list
	int Size();

	// Delete all elements from the linked list
	void CleanUp();
	
	// Print the list
	void Print();

};

/*
 *	Implementation
 */

template <typename Type>
LinkedList<Type>::LinkedList()
{

}

template <typename Type>
LinkedList<Type>::~LinkedList()
{

}

template <typename Type>
Type LinkedList<Type>::Get(const int index)
{

}

template <typename Type>
void LinkedList<Type>::AddAtHead(const Type& val)
{

}

template <typename Type>
void LinkedList<Type>::AddAtIndex(const int index, const Type& val)
{

}

template <typename Type>
void LinkedList<Type>::DeleteAtIndex(const int index)
{

}

template <typename Type>
void LinkedList<Type>::DeleteValue(const Type& val)
{

}

template <typename Type>
void LinkedList<Type>::MoveToHead(const Type& val)
{

}

template <typename Type>
void LinkedList<Type>::Rotate(const int steps)
{

}

template <typename Type>
void LinkedList<Type>::Reduce()
{

}

template <typename Type>
void LinkedList<Type>::K_Reverse(const int k)
{

}

template <typename Type>
void LinkedList<Type>::EvenOddSeparateSort() 
{

}

template <typename Type>
int LinkedList<Type>::Size()
{

}

template <typename Type>
void LinkedList<Type>::CleanUp()
{

}

template <typename Type>
void LinkedList<Type>::Print()
{

}


#endif