#include <iostream>
#include <vector>
#include <bits/stdc++.h>

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
  std::vector<int> content;  
  
  int pop();
  void push(int);
  int getMin();  
};

int Stack::pop() {
  while (top != nullptr) {
    Node* temp = top;
    top = top->below;
    return temp->data;
  }
  std::cerr << "No node found" << std::endl;
  return 1;
}

void Stack::push(int data) {
  Node* newNode = new Node(data);
  if (top != nullptr) {
    newNode->below = top;
    top = newNode;
  } else {
    top = newNode;
  }
  content.push_back(top->data);
  return;
}

int Stack::getMin() {
  return *min_element(content.begin(), content.end());
};

int main() {
  Stack stack;
  stack.push(91);
  stack.push(22);
  stack.push(4);
  stack.push(104);
  std::cout << stack.getMin() << std::endl;
}
