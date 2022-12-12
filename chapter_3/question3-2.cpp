#include <iostream>
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
  Stack() { 
  top = nullptr;
  fullStack = false;
  stackSize = 0;
  }
  int stackSize;
  bool fullStack;
  int pop();
  void push(int);
  Node* getTop();
};

Node* Stack::getTop() {
  return top;
}
//MAKES TWO NEW BEGINNINGS IN A ROW TODO: issue is new stack being created not issue within this
void Stack::push(int data) {
  Node* newNode = new Node(data);
  if (top != NULL) {
    Node* temp = top;
    top = newNode;
    top->below = temp;
  } else {
    top = newNode;
  }  
  stackSize++;
  if (stackSize == 10) {
    fullStack = true;
  }
}

int Stack::pop() {
  if (top == NULL) { std::cerr << "no content" << std::endl; }
  Node* temp = top;
  top = top->below;
  return temp->data;
}

class ManyStacks {
public: 
  int items;
  std::vector<Stack> stacks;
  ManyStacks() { 
    items = 0;
    Stack newStack;
    stacks.push_back(newStack);
  }
  void push(int);
  int pop();
  Stack& currentStack();
  void printAll();
};

Stack& ManyStacks::currentStack() {
  int index = stacks.size()-1;
  //called a ton
  //std::cout << "the current stack index is: " << index << std::endl;
  /*
  if (stacks[index].stackSize == 10) {
    stacks[index].fullStack = true;
  }
  */
  return stacks[index];
}
//produces 14 items so if the push is functioning then its good: TODO check stack push, checked here again for issue with bool value but constructor should account for this.
void ManyStacks::push(int data) {
  if (currentStack().fullStack) {
    Stack newStack;
    stacks.push_back(newStack);
//    newStack.push(data);
  }
  items++;
  currentStack().push(data);
  return;
}
int ManyStacks::pop() {
  if (currentStack().getTop() == NULL) {
    stacks.erase(stacks.end() - 1);
  }  
  return currentStack().pop();
}
void ManyStacks::printAll() {
  int size = stacks.size();
  for (int i = 0; i < items - 1; i++) {
    std::cout << pop() << std::endl;
  }
  return;
}


int main() {
  ManyStacks bigBoy;
  bigBoy.push(1);
  bigBoy.push(2);
  bigBoy.push(3);
  bigBoy.push(4);
  bigBoy.push(5);
  bigBoy.push(6);
  bigBoy.push(7);
  bigBoy.push(8);
  bigBoy.push(9);
  bigBoy.push(10);
  bigBoy.push(11);
  bigBoy.push(12);
  bigBoy.push(13);
  bigBoy.push(14);
  bigBoy.printAll();
  return 0;
}
