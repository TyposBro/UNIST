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

	// Delete an element located at index
	void DeleteAtIndex(const int index);

	// Delete val in linked list
	void DeleteValue(const Type &val);

	// Move the first element of val to head
	void MoveToHead(const Type &val);

	// Rotate the linked list right by steps times
	void Rotate(const int steps);

	// Reduce value that repeats multiple times
	void Reduce();

	// // Reverse at every k number of nodes at a time
	// void K_Reverse(const int k);

	// // Sort even and odd numbers separately then append
	// void EvenOddSeparateSort();

	// Return the number of elements in the linked list
	int Size();

	// Delete all elements from the linked list
	void CleanUp();

	// Print the list
	void Print();

	// My helper function for AddAtIndex

	// Add at the end of the list
	void append(const Type &val);
	// Remove from the beginning of the list
	void shift();
	// Remove from the end of the list
	void pop();
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
	if (index <= -1 || index >= Size())
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
	int size = Size();
	if (index <= -1 || index > size)
	{
		return;
	}
	if (index == 0)
	{
		AddAtHead(val);
		return;
	}
	if (index == size)
	{
		append(val);
	}

	int step = 0;
	Node<Type> *ptr = head;
	Node<Type> *prev = ptr;
	while (ptr->next != NULL && index != step)
	{
		prev = ptr;
		ptr = ptr->next;
		step++;
	}
	Node<Type> *newNode = new Node<Type>(val, ptr);
	prev->next = newNode;
	return;
}

template <typename Type>
void LinkedList<Type>::DeleteAtIndex(const int index)
{
	int size = Size();
	int step = 0;
	Node<Type> *ptr = head;
	Node<Type> *prev = ptr;
	if (index <= -1 || index >= size)
	{
		return;
	}
	if (index == 0)
	{
		shift();
	}
	if (index == size - 1)
	{
		pop();
	}

	while (index != step)
	{
		prev = ptr;
		ptr = ptr->next;
		step++;
	}
	prev->next = ptr->next;
	delete ptr;
}

template <typename Type>
void LinkedList<Type>::DeleteValue(const Type &val)
{
	Node<Type> *ptr = head;
	Node<Type> *prev = ptr;
	while (ptr != NULL && ptr->data != val)
	{
		prev = ptr;
		ptr = ptr->next;
	}
	if (ptr->data == val)
	{
		prev->next = ptr->next;
		delete ptr;
	}
}

template <typename Type>
void LinkedList<Type>::MoveToHead(const Type &val)
{
	Node<Type> *ptr = head;
	Node<Type> *prev = ptr;
	while (ptr != NULL && ptr->data != val)
	{
		prev = ptr;
		ptr = ptr->next;
	}
	if (ptr->data == val)
	{
		prev->next = ptr->next;
		AddAtHead(ptr->data);
	}
}

template <typename Type>
void LinkedList<Type>::Rotate(const int steps)
{
	int lastItemIndex = Size() - 1;
	int step = 0;

	Node<Type> *ptr = head;
	if (steps <= 0)
	{
		return;
	}
	while (step != steps)
	{
		step++;
		int data = Get(lastItemIndex);
		AddAtHead(data);
		pop();
	}
}

template <typename Type>
void LinkedList<Type>::Reduce()
{
	Node<Type> *ptr = head;

	while (ptr != NULL && ptr->next != NULL)
	{

		Node<Type> *secondLoop = ptr;
		while (secondLoop->next != NULL)
		{

			if (ptr->data == secondLoop->next->data)
			{
				Node<Type> *temp = secondLoop->next;
				secondLoop->next = secondLoop->next->next;
				delete temp;
				continue;
			}
			secondLoop = secondLoop->next;
		}
		ptr = ptr->next;
	}
}

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

// Helper functions
template <typename Type>
void LinkedList<Type>::append(const Type &val)
{
	Node<Type> *ptr = head;
	while (ptr->next != NULL)
	{
		ptr = ptr->next;
	}
	Node<Type> *newNode = new Node<Type>(val);
	ptr->next = newNode;
}

template <typename Type>
void LinkedList<Type>::shift()
{
	Node<Type> *ptr = head;
	head = head->next;
	delete ptr;
};

template <typename Type>
void LinkedList<Type>::pop()
{
	Node<Type> *ptr = head;
	Node<Type> *prev = ptr;
	while (ptr->next != NULL)
	{
		prev = ptr;
		ptr = ptr->next;
	}
	prev->next = NULL;
	delete ptr;
};

#endif