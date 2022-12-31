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
  int stackSize = 0;
  Stack() {
    top = nullptr;
  }
  int pop();
  void push(int);
  int peek();
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
      std::cout << "stack added" << std::endl;
      TowerVector[0]->push(startSize - i);
    }
  }
  /* void sortTowers(); */
  void solveTower(int size);
};
void Towers::solveTower(int size) {
  std::cout << TowerVector[2]->stackSize << std::endl;
  std::cout << size << std::endl;
  while(TowerVector[2]->stackSize <= size) {
    if(TowerVector[0]->peek() > TowerVector[2]->peek() && TowerVector[2]->peek() != 0) {
      std::cout << TowerVector[2]->peek() << " moving to stack 1" << std::endl;
      TowerVector[0]->push(TowerVector[2]->pop());
    } else {
      std::cout << TowerVector[0]->peek() << " moving to stack 3" << std::endl;
      TowerVector[2]->push(TowerVector[0]->pop());
    }
    if(TowerVector[0]->peek() > TowerVector[1]->peek() && TowerVector[1]->peek() != 0) {
      std::cout << TowerVector[1]->peek() << " moving to stack 1" << std::endl;
      TowerVector[0]->push(TowerVector[1]->pop());
    } else {
      if(TowerVector[0]->peek() == 0) {
        std::cout << TowerVector[1]->peek() << " moving to stack 1" << std::endl;
        TowerVector[0]->push(TowerVector[1]->pop());
      } else {
        std::cout << TowerVector[0]->peek() << " moving to stack 2" << std::endl;
        TowerVector[1]->push(TowerVector[0]->pop());
      }
    }
    if(TowerVector[1]->peek() > TowerVector[2]->peek() && TowerVector[2]->peek() != 0) {
      std::cout << TowerVector[2]->peek() << " moving to stack 2" << std::endl;
      TowerVector[1]->push(TowerVector[2]->pop());
    } else {
      std::cout << TowerVector[1]->peek() << " moving to stack 3" << std::endl;
      TowerVector[2]->push(TowerVector[1]->pop());
    }
  }
  std::cout << "complete" << std::endl;
}
/*
void Towers::solveTower(int size, int start, int end) {
  if (size == 1) {
    std::cout << "attempting to pop from stack: " << start << std::endl;
    int data = this->TowerVector[start]->pop();
    this->TowerVector[end]->push(data);
  } else {
    int other = 6 - (start + end);
    solveTower(size - 1, start, other);
    std::cout << "attempting to pop from stack: " << start << std::endl;
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
  if (top == nullptr) {
    std::cerr << "top of stack is null, cannot pop"
      << std::endl;
  }
  stackSize--;
  int temp = top->data;
  top = top->next;
  return temp;
}

int Stack::peek() {
  if (top == nullptr) {
    return 0;
  } else {
  return top->data;
  }
}

void Stack::push(int data) {
  Node* newNode = new Node(data);
  if (top == nullptr) {
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
  Towers tower(3, 3);
  tower.solveTower(3);
  return 0;
}
