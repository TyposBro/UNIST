#ifndef NODE_H
#define NODE_H

#include <iostream>

using namespace std;

template <typename type>
struct Node
{
  type data;
  Node<type> *next;

  Node(type d) : data(d), next(NULL){};
  Node(type d, Node<type> *n) : data(d), next(n) {}
};

#endif // NODE_H

#ifndef STACK_H
#define STACK_H

#include <iostream>

using namespace std;

template <typename type>
class Stack
{
private:
  Node<type> *_top;

public:
  // Constructor
  explicit Stack();

  // Destructor
  ~Stack();

  // Store new element
  void push(const type &item);

  // Return first element
  type &top() const;

  // Remove first element
  void pop();

  // Return true if empty, false otherwise
  bool empty() const;

  // Number of elements stored
  int size() const;
};

// Implement functions below

template <typename type>
Stack<type>::Stack()
{
  _top = NULL;
}

template <typename type>
Stack<type>::~Stack()
{
  while (_top)
  {
    Node<type> *tmp = _top;
    tmp->next = NULL;
    _top = _top->next;
    delete tmp;
  }
}

template <typename type>
void Stack<type>::push(const type &item)
{

  if (empty())
  {
    _top = new Node<type>(item);
    return;
  }
  Node<type> *temp = _top;
  _top = new Node<type>(item, temp);
}

template <typename type>
type &Stack<type>::top() const
{
  return _top->data;
}

template <typename type>
void Stack<type>::pop()
{
  if (empty())
    return;

  Node<type> *temp = _top;
  _top = _top->next;
  temp->next = NULL;
  delete temp;
}

template <typename type>
bool Stack<type>::empty() const
{
  return (_top == NULL);
}

template <typename type>
int Stack<type>::size() const
{
  Node<type> *ptr = _top;
  int count = 0;
  while (ptr)
  {
    count++;
    ptr = ptr->next;
  }

  return count;
}

#endif // STACK_H
