

#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include "stack.h"

using namespace std;

template <typename type>
class Queue
{

private:
  Node<type> *_front;
  Node<type> *_rear;

public:
  // Constructor
  explicit Queue();

  // Destructor
  ~Queue();

  // Store new element
  void push(const type &item);

  // Return first element
  type &front() const;

  // Remove first element
  void pop();

  // Return true if empty, false otherwise
  bool empty() const;

  // Number of elements stored
  int size() const;
};

// Implement functions below

template <typename type>
Queue<type>::Queue()
{
  _front = NULL;
  _rear = NULL;
}

template <typename type>
Queue<type>::~Queue()
{
}

template <typename type>
void Queue<type>::push(const type &item)
{
  Node<type> *newNode = new Node<type>(item);

  if (!_rear)
  {
    _rear = newNode;
    _front = _rear;
    return;
  }
  _rear->next = newNode;
  _rear = newNode;
}

template <typename type>
type &Queue<type>::front() const
{
  return _front->data;
}

template <typename type>
void Queue<type>::pop()
{
  if (!_front)
    return;

  Node<type> *temp = _front;
  _front = _front->next;

  if (!_front)
    _rear = NULL;

  delete (temp);
}

template <typename type>
bool Queue<type>::empty() const
{
  return (_front == NULL && _rear == NULL);
}

template <typename type>
int Queue<type>::size() const
{
  Node<type> *ptr = _front;
  int count = 0;

  while (ptr)
  {
    count++;
    ptr = ptr->next;
  }

  return count;
}

#endif // QUEUE_H