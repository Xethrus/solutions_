#include <iostream>

class Node {
public:
  int data:
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
    stackSize = 0;
    numberTag = 0;
  }
  int numberTag;
  int stackSize;
  int pop();
  void push(int); 
};

int Stack::pop() {
  if (top == NULL) {
    std::cerr << "null top" << std::endl;
  }
  int value = top->data;
  top = top->below;
  return value;
}

void Stack::push(int data) {
  Node* newNode = new Node(data);
  if (top == NULL) {
    top = newNode;
  } else {
    Node* temp = top;
    top = newNode;
    top->below = temp;
  }
  stackSize++;
}

class Towers {
public:
  Towers() {
    Stack Tower1;
    Tower1.number = 1;
    Stack Tower2;
    Tower1.number = 2;
    Stack Tower3;
    Tower1.number = 3;
  }
  void startPuzzle(int);
  void sortTowers(int, Stack&, Stack&);
  void makeMove(int, Stack&, Stack&);
  Stack& findOther(Stack&, Stack&); 
}

void Towers::startPuzzle(int towerSize) {
  for (int i = 0; i <= towerSize; i++) {
    Tower1.push(towerSize - i);  
  } 
  return;
}
void Towers::makeMove(Stack& start, Stack& end) {
  int ring = start.pop();
  end.push(ring);
  std::cout << start.top->data << " -> " <<
    end.top->data << std::endl;
}
Stack& Towers::findOther(Stack& start, Stack& end) {
    int nextTowerNum = 6 - (start.number, + end.number);
    if (Tower1.number == nextTowerNum) {
      Towers.sortTowers(totalRings - 1, start, Tower1);
    }
    if (Tower2.number == nextTowerNum) {
      Towers.sortTowers(totalRings - 1, start, Tower2);
    }
    if (Tower3.number == nextTowerNum) {
      Towers.sortTowers(totalRings - 1, start, Tower3);
    }
}
void Towers::sortTowers(int totalRings,
    Stack& start, Stack& end) {
  if (totalRings == 1) {
    Towers.makeMove(start, end); 
  } else {
    Towers.sortTowers(totalRings - 1, start,
        Towers.findOther(start, end));
    Towers.makeMove(start, end);
    Towers.sortTowers(totalRings - 1,
        Towers.findOther(start, end), end);
  }
}




