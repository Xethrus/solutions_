#include <iostream>
#include <vector>
#include <string>

class Node {
public:
  Node* next;
  std::string catOrDog;
  Node() {
    next = nullptr;
  }
  Node(std::string dogOrCat) { 
    next = nullptr;
    catOrDog = dogOrCat;
  }
};

class Queue {
public:
  Node* front;
  Node* rear;
  Queue() {
    front = nullptr;
    rear = nullptr;
  }
  void enqueue(std::string);
  std::string dequeue();
};

void Queue::enqueue(std::string species) {
  Node* newNode = new Node(species);
  if(this->front == nullptr && this->rear == nullptr) {
    this->front = newNode;
    this->rear = newNode;
  } else {
    this->front->next = newNode;
    this->front = newNode;
  }
}

std::string Queue::dequeue() {
  if(this->front == nullptr && this->rear == nullptr) {
    std::cerr << "ERROR NO CONTENTS" << std::endl;
    return "failure of code";
  } else {
    std::string species = this->rear->catOrDog;
    this->rear = this->rear->next;
    /*
    std::cout << this->front->next->catOrDog << std::endl;
    this->front = this->front->next;
    */
    return species;
  }
}

int main() {
  Queue test;
  test.enqueue("1");
  test.enqueue("2");
  test.enqueue("3");
  test.enqueue("4");
  test.enqueue("5");
  std::cout << "removing from beginning of queue: " <<
    test.dequeue() << std::endl;
  std::cout << "rear: " << test.rear->catOrDog << std::endl;
  std::cout << "front: " << test.front->catOrDog << std::endl;
  return 0;
}
