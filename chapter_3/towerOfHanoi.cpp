#include <iostream>
#include <vector>

void printMove(int start, int end) {
  std::cout << start << " -> " << end << std::endl;
}

void solveTower(int size, int start, int end){
  if (size == 1) {
    printMove(start, end);
  } else {
    int other = 6 - (start + end);
    solveTower(size - 1, start, other);
    printMove(start, end);
    solveTower(size - 1, other, end);
  }
}

class Node {
public:
  int data;
  Node* next;
  Node() { data = 0; next = NULL; }
  Node(int data) {
    this->data = data;
    this->next = NULL;
  }
};

class Stack {
  Node* top;
public:
  int stackSize;
  Stack() {
    top = nullptr;
    stackSize = 0;
  }
  int pop();
  void push(int);
};

int Stack::pop() {
  if (top == NULL) {
    std::cerr << "top of stack is null, cannot pop"
      << std::endl;
  }
  int temp = top->data;
  top = top->next;
  return temp;
}

void Stack::push(int data) {
  Node* newNode = new Node(data);
  if (top == NULL) {
    top = newNode;
  } else {
    Node* temp = top;
    top = newNode;
    top->next = temp;
  }
  stackSize++;
  return;
}

std::vector<Stack *> makeTowers(int amountofTowers, int startingSize) {
  std::vector<Stack *> towers;
  for(int i = 0; i < amountofTowers; i++) {
    towers.push_back(new Stack);
  } 
  for(int i = 0; i < startingSize; i++) {
    int value = startingSize - i;
    towers[0]->push(value);
  }
  return towers;
}
void sortTowers(std::vector<Stack *> stacks, int size) {
  if (size == 1) {
    printMove(1, size);
    int data = stacks[0]->pop();
    stacks[size]->push(data);
  } else {
    //assuming three towers
    int other = 6 - (0 + size);
    sortTowers(s
    
  }

}

int main() {
  return 0;
}
