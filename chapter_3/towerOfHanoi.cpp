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

class Towers { 
public:
  std::vector<Stack*> TowerVector;
  int startSize;
  int numberOfPegs;
  Towers(int startSize, int numberOfPegs) {
    startSize = startSize;
    numberOfPegs = numberOfPegs;
    for(int i = 0; i < numberOfPegs; i++) {
      TowerVector.push_back(new Stack);
    }
    for(int i = 0; i < startSize; i++) {
      TowerVector[0]->push(startSize - i);
    }
  }
  /* void sortTowers(); */
  void solveTower(int size, int start, int end);
};

void Towers::solveTower(int size, int start, int end) {
  if (size == 1) {
    int data = this->TowerVector[start]->pop();
    this->TowerVector[end]->push(data);
  } else {
    int other = 6 - (start + end);
    solveTower(size - 1, start, other);
    int data = this->TowerVector[start]->pop();
    this->TowerVector[end]->push(data);
    solveTower(size - 1, other, end);
  }
}
/*
void Towers::sortTowers() {
  if (this->startSize == 1) {
    printMove(0, this->numberOfPegs)
    int data = this->TowerVector[0]->pop();
    this->TowerVector[this->numberOfPegs]->push(data);
    return;
  } else {
    int other = 6 - (0 + this->numberOfPegs);
    this->startSize -= 1;
    int data = this->TowerVector[0]->pop();
    this->TowerVector[other]->push(data);
    int data = this->Tower[other]->pop();
    this->TowerVecotr[end]->push(data);
    sortTowers();
  }
}
*/
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

int main() {
  Towers tower(10, 3);
  tower.solveTower(10,1,3);
  return 0;
}
