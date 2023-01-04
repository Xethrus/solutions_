#include <iostream>

class Node {
public:
  int data;
  Node* below;
  Node() { data = 0; below = NULL; }
  Node(int data) {
    this->data = data;
    this->below = NULL;
  }
};

class Stack {
  Node* top;
public:
  Stack() { 
    top = NULL;
    stackSize = 0;
  }
  int stackSize;
  void push(int);
  int pop();
  int peek();
  bool isEmpty();
  void sortStack();
  void actOnStack();
};

void Stack::push(int data) {
  Node* newNode = new Node(data);
  stackSize++;
  if (top == NULL) {
    top = newNode; 
  }
  newNode->below = top;
  top = newNode;
  return;
}

int Stack::pop() {
  if (top == NULL) {
    //doesnt even say anything TODO
    std::cerr << "FAILURE NO NODE FOUND" << std::endl;
    return -1;
  } else {
    Node* temp = top;
    top = top->below;
    std::cout << "POPPING: " << temp->data << std::endl;
    return temp->data;
  }
}

int Stack::peek() {
  if (top == NULL) {
    std::cerr << "NO CONTENT TO PEEK" << std::endl;
    return NULL;
  } else {
    return top->data;
  }
}

bool Stack::isEmpty() {
  if (top == NULL) {
    return true; 
  } else {
    return false;
  }
}
/*
void Stack::sortStack() {
  Stack bufferStack;
  int bufferInt;
  bufferInt = this->pop();
  while(this != nullptr) {
    if(this->data > bufferInt) {
      bufferStack.push(this->pop());
    }
  }
  this->push(bufferInt);
  while(bufferStack != nullptr) {
    this->push(bufferStack.pop());
  }
  return;
}
*/
void Stack::sortStack() {
  int buffer = this->pop();
  Stack bufferStack;
  while(buffer <= this->peek()) {
    bufferStack->push(this->pop());
  } else {
    this->push(buffer);
  }
  while(!bufferStack.isEmpty()) {
    this->push(bufferStack.pop());
  }
  if(
}

int main() {
  Stack stack;
  stack.push(1);
  stack.push(1);
  stack.push(5);
  stack.push(1);
  stack.push(1);
  return 0;
}
