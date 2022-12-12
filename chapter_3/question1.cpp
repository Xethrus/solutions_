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
    int arraySize = 9;
    int array[9] = {1,2,3,4,5,6,7,8,9};
    Node* pop();
    void push(int);
    void peek();
    void fillThreeStacks();
    void printStack();
};

Node* Stack::pop() {
  while (top != nullptr) {
    Node* temp = top;
    top = top->below;
    return temp;
  }
  return nullptr;
}
void Stack::printStack() { 
  for(int i = 0; i < 3; i++) {
    Node* temp = pop();
    if (temp != nullptr) {
      std::cout << "temp: " << temp << std::endl;
      std::cout << "data: " << temp->data << std::endl;
    }
  }
  return;
}

void Stack::push(int data) {
  Node* newNode = new Node(data);
  if (top != nullptr) {
    newNode->below = top;
    top = newNode; 
  } else {
    top = newNode;
  }
  return;
}
void Stack::fillThreeStacks() {
  Stack stack1;
  Stack stack2;
  Stack stack3;
  if (arraySize < 3) {
    std::cout << "not enough elements in array" << std::endl;
    return;
  }
  for (int i = 0; i < arraySize; i += 3) {
    stack1.push(array[i]);
    stack2.push(array[i+1]);
    stack3.push(array[i+2]);
  }
  stack1.printStack();
  stack2.printStack();
  stack3.printStack();
}
int main() {
  Stack stack;
  stack.fillThreeStacks();
  return 0;
}
