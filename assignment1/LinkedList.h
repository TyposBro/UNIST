// CSE221 Assignment 1

#ifndef LinkedList_h
#define LinkedList_h

#include <typeinfo>
#include <iostream>
using namespace std;

template <typename Type>
struct Node
{
	Type data;
	Node<Type> *next;

	Node(Type data, Node<Type> *next = NULL) : data(data), next(next){};
};

template <typename Type>
class LinkedList
{
private:
	Node<Type> *head;

public:
	// Constructor
	LinkedList();

	// Destructor
	~LinkedList();

	// Get the value located at index
	Type Get(const int index);

	// Add val at head
	void AddAtHead(const Type &val);

	// Add val at index
	void AddAtIndex(const int index, const Type &val);

	// // Delete an element located at index
	// void DeleteAtIndex(const int index);

	// // Delete val in linked list
	// void DeleteValue(const Type &val);

	// // Move the first element of val to head
	// void MoveToHead(const Type &val);

	// // Rotate the linked list right by steps times
	// void Rotate(const int steps);

	// // Reduce value that repeats multiple times
	// void Reduce();

	// // Reverse at every k number of nodes at a time
	// void K_Reverse(const int k);

	// // Sort even and odd numbers separately then append
	// void EvenOddSeparateSort();

	// // Return the number of elements in the linked list
	int Size();

	// // Delete all elements from the linked list
	void CleanUp();

	// // Print the list
	void Print();
};

/*
 *	Implementation
 */

template <typename Type>
LinkedList<Type>::LinkedList()
{
	head = NULL;
}

template <typename Type>
LinkedList<Type>::~LinkedList()
{
	while (Size() > 0)
	{
		CleanUp();
	}
}

template <typename Type>
Type LinkedList<Type>::Get(const int index)
{
	int step = 0;
	Node<Type> *ptr = head;
	if (index <= -1 && index >= Size())
	{
		return -1;
	}
	while (step != index)
	{
		ptr = ptr->next;
		step++;
	}
	return ptr->data;
}

template <typename Type>
void LinkedList<Type>::AddAtHead(const Type &val)
{
	if (!head)
	{
		head = new Node<Type>(val);
		head->data = val;
		head->next = NULL;
		return;
	}

	Node<Type> *ptr = head;
	head = new Node<Type>(val, ptr);
	return;
}

template <typename Type>
void LinkedList<Type>::AddAtIndex(const int index, const Type &val)
{
}

// template <typename Type>
// void LinkedList<Type>::DeleteAtIndex(const int index)
// {
// }

// template <typename Type>
// void LinkedList<Type>::DeleteValue(const Type &val)
// {
// }

// template <typename Type>
// void LinkedList<Type>::MoveToHead(const Type &val)
// {
// }

// template <typename Type>
// void LinkedList<Type>::Rotate(const int steps)
// {
// }

// template <typename Type>
// void LinkedList<Type>::Reduce()
// {
// }

// template <typename Type>
// void LinkedList<Type>::K_Reverse(const int k)
// {
// }

// template <typename Type>
// void LinkedList<Type>::EvenOddSeparateSort()
// {
// }

template <typename Type>
int LinkedList<Type>::Size()
{
	Node<Type> *ptr = head;
	int count = 0;
	while (ptr != NULL)
	{
		ptr = ptr->next;
		count++;
	}
	return count;
}

template <typename Type>
void LinkedList<Type>::CleanUp()
{
	Node<Type> *ptr = head;
	while (head != NULL)
	{
		ptr = head;
		head = head->next;
		delete ptr;
	}
}

template <typename Type>
void LinkedList<Type>::Print()
{
	Node<Type> *ptr = head;
	cout << "(";
	while (ptr->next != NULL)
	{
		cout << ptr->data << ",";
		ptr = ptr->next;
	}
	cout << ptr->data << ")" << endl;
}

#endif