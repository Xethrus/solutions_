#include <iostream>
//implement a queue using two stacks

class Node {
public:
  int data;
  Node* next;
  Node() {
    data = 0; 
    next = nullptr;
  }
  Node(int data) {
    this->data = data;
    this->next = nullptr;
  }
};

class Stack {
  Node* top;
public:
  Stack() {top = nullptr;}
  
  int pop();
  void push(int);
};

int Stack::pop() {
  if (top == NULL) {
    std::cerr << "NULL element top" << std::endl;
    return
  } else {
    Node* temp = top;
    top = top->next;
    return temp->data;
  }
}

void Stack::push(int data) {
  Node* newNode = new Node(data);
  if (top == NULL) {
    top = newNode;
  } else {
    newNode->next = top;
    top = newNode;
  }
  return;
}

class Queue {
public:
  Stack inbox;
  Stack outbox;
  void newItem(int);
  void checkoutItems();
};

void Queue::newItem(int data) {
  this->inbox.push(data);
  this->outbox.push(inbox.pop());
  checkoutItems();
}

void Queue::checkoutItems() {
  std::cout << "checking out item: " <<
    this->outbox.pop() << std::endl;
}


int main() {
  Queue mail;
  mail.newItem(7);
}
