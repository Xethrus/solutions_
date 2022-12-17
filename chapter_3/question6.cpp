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
  Stack() { top = nullptr; }
  void push(int);
  int pop();
  int peek();
  bool isEmpty();
  void sortStack();
};

void Stack::push(int data) {
  Node* newNode = new Node(data);
  if (top == NULL) {
    top = newNode; 
  }
  newNode->below = top;
  top = newNode;
  return;
}

int Stack::pop() {
  if (top == NULL) {
    std::cerr << "FAILURE NO NODE FOUND" << std::endl;
    return -1;
  } else {
    Node* temp = top;
    top = top->below;
    return temp->data;
  }
}

int Stack::peek() {
  if (top == NULL) {
    std::cerr << "NO CONTENT TO PEEK" << std::endl;
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
//O n^2 
void Stack::sortStack() {
  Stack buffer;
  int tempValue;

  while(!this->isEmpty()) {
    tempValue = this->peek();
    this->pop();
    while(!buffer.isEmpty() && buffer.peek() < tempValue) {
      this->push(buffer.peek());
      buffer.pop();
    }
    buffer.push(tempValue);
  }
  while(!buffer.isEmpty()) {
    std::cout << buffer.peek() << std::endl;
    buffer.pop();
  }
}

int getSmaller(int a, int b) {
  if (a < b) {
    return a;
  } else {
    return b;
  }
}

int main() {
  Stack stack;
  stack.push(1);
  stack.push(3);
  stack.push(5);
  stack.push(5);
  stack.push(1);
  stack.push(4);
  stack.sortStack();
  return 0;
}
