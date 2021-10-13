#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

using namespace std;

template <typename type>
class Queue {

public:
  // Constructor
  explicit Queue();

  // Destructor
  ~Queue();

  // Store new element
  void push(const type& item);

  // Return first element
  type& front() const;

  // Remove first element
  void pop();

  // Return true if empty, false otherwise
  bool empty() const;

  // Number of elements stored
  int size() const;

};

// Implement functions below

template <typename type>
Queue<type>::Queue() {

}

template <typename type>
Queue<type>::~Queue() {

}


template <typename type>
void Queue<type>::push(const type &item) {

}

template <typename type>
type& Queue<type>::front() const {

}

template <typename type>
void Queue<type>::pop() {

}

template <typename type>
bool Queue<type>::empty() const {

}

template <typename type>
int Queue<type>::size() const {

}

#endif //QUEUE_H
