#include <iostream>
#include <algorithm> 
#include <vector>

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
  std::vector<int> getContent();
};

class Stacks {
public: 
  Stacks() { Stack stack; }
  std::vector<int> allContent;
  std::vector<Stack> stackVector;
  const int MAX_HEIGHT = 10;
  int pop();
  void push(int);
  void grabContent();
}

void Stacks::grabContent() {
  allConent.insert(allContent.end(), content.begin(), content.end());
}

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
  if(content.size() == MAX_HEIGHT) {
    
  }
  if (top != nullptr) {
    newNode->below = top;
    top = newNode;
  } else {
    top = newNode;
  }
  content.push_back(top->data);
  return;
  }
}

void Stack::getContent() {
  return content;
}
