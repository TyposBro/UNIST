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

	// *** My helper function for AddAtIndex *** //

	// Add at the end of the list
	void append(Node<Type> *head, const Type &val);

	// Remove from the beginning of the list
	void shift();

	// Remove from the end of the list
	void pop();

	// reverseBetween(Node<Type> *start, Node<Type> *end)
	Node<Type> *reverseBetween(Node<Type> *start, Node<Type> *end);

	//
	void ascEven(Node<Type> **even, Node<Type> *val);
	void descOdd(Node<Type> **odd, Node<Type> *val);
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

		append(head, val);
		return;
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
	while (ptr && ptr->data != val)
	{
		prev = ptr;
		ptr = ptr->next;
	}
	if (ptr && ptr->data == val)
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
	while (ptr && ptr->data != val)
	{
		prev = ptr;
		ptr = ptr->next;
	}
	if (ptr && ptr->data == val)
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
	while (ptr && step != steps)
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

	while (ptr && ptr->next != NULL)
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

template <typename Type>
void LinkedList<Type>::K_Reverse(const int k)
{

	if (!head || !head->next)
	{
		return;
	}
	Node<Type> *preHead = new Node<Type>(-1, head);
	Node<Type> *start = preHead;
	int i = 0;
	while (head)
	{
		i++;
		if (i % k == 0)
		{
			start = reverseBetween(start, head->next);
			head = start->next;
		}
		else
		{
			head = head->next;
		}
	}

	head = preHead->next;
}

template <typename Type>
void LinkedList<Type>::EvenOddSeparateSort()
{
	Node<Type> *ptr = head;
	Node<Type> *even = NULL;
	Node<Type> *odd = NULL;
	while (ptr)
	{
		if (ptr->data % 2 == 0)
		{
			ascEven(&even, ptr);
		}
		else
		{
			descOdd(&odd, ptr);
		}

		ptr = ptr->next;
	}
	ptr = even;
	while (ptr->next)
	{
		ptr = ptr->next;
	}
	ptr->next = odd;
	head = even;
}

template <typename Type>
int LinkedList<Type>::Size()
{
	Node<Type> *ptr = head;
	int count = 0;
	while (ptr)
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
	while (head)
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
	if (!ptr)
	{
		return;
	}

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
void LinkedList<Type>::append(Node<Type> *head, const Type &val)
{
	Node<Type> *ptr = head;
	while (ptr && ptr->next)
	{
		ptr = ptr->next;
	}
	ptr->next = new Node<Type>(val);
}

template <typename Type>
void LinkedList<Type>::shift()
{
	if (!head)
	{
		return;
	}

	Node<Type> *ptr = head;
	head = head->next;
	delete ptr;
};

template <typename Type>
void LinkedList<Type>::pop()
{
	if (!head)
	{
		return;
	}

	Node<Type> *ptr = head;
	Node<Type> *prev = ptr;
	while (ptr->next)
	{
		prev = ptr;
		ptr = ptr->next;
	}
	prev->next = NULL;
	delete ptr;
};

template <typename Type>
Node<Type> *LinkedList<Type>::reverseBetween(Node<Type> *start, Node<Type> *end)
{
	Node<Type> *ptr = start->next;
	Node<Type> *prev = start;
	Node<Type> *first = ptr;
	Node<Type> *next;

	while (ptr != end)
	{
		next = ptr->next;
		ptr->next = prev;
		prev = ptr;
		ptr = next;
	}
	start->next = prev;
	first->next = ptr;
	return first;
};

template <typename Type>
void LinkedList<Type>::ascEven(Node<Type> **even, Node<Type> *val)
{
	Node<Type> *ptr = *even;
	Node<Type> *prev = ptr;

	if (!ptr)
	{
		*even = new Node<Type>(val->data);
		return;
	}
	else if (ptr->data > val->data)
	{
		*even = new Node<Type>(val->data, ptr);
		return;
	}
	while (ptr && ptr->data < val->data)
	{
		prev = ptr;
		ptr = ptr->next;
	}

	prev->next = new Node<Type>(val->data, ptr);
};

template <typename Type>
void LinkedList<Type>::descOdd(Node<Type> **odd, Node<Type> *val)
{
	Node<Type> *ptr = *odd;
	Node<Type> *prev = ptr;

	if (!ptr)
	{
		*odd = new Node<Type>(val->data);
		return;
	}
	else if (ptr->data < val->data)
	{
		*odd = new Node<Type>(val->data, ptr);
		return;
	}
	while (ptr && ptr->data > val->data)
	{
		prev = ptr;
		ptr = ptr->next;
	}

	prev->next = new Node<Type>(val->data, ptr);
};
#endif