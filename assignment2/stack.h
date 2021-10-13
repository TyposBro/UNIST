#ifndef STACK_H
#define STACK_H

#include <iostream>

using namespace std;

template <typename type>
class Stack {

public:
  // Constructor
  explicit Stack();

  // Destructor
  ~Stack();

  // Store new element
  void push(const type& item);

  // Return first element
  type& top() const;

  // Remove first element
  void pop();

  // Return true if empty, false otherwise
  bool empty() const;

  // Number of elements stored
  int size() const;
};

// Implement functions below

template <typename type>
Stack<type>::Stack() {

}

template <typename type>
Stack<type>::~Stack() {

}

template <typename type>
void Stack<type>::push(const type &item) {

}

template <typename type>
type& Stack<type>::top() const {

}

template <typename type>
void Stack<type>::pop() {

}

template <typename type>
bool Stack<type>::empty() const {

}

template <typename type>
int Stack<type>::size() const {

}

#endif //STACK_H
