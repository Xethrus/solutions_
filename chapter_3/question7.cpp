#include <iostream>
#include <vector>

class AnimalNode {
  std::string catOrDog;
  int year;
  int month;
  int day;
  AnimalNode* nextAnimal;
  AnimalNode* prevAnimal;

  AnimalNode() {
    year = 0;
    month = 0;
    day = 0;
    nextAnimal = nullptr;
    prevAnimal = nullptr;
  }
  AnimalNode(string species, int year, int month, int day) {
    catOrDog = species;
    year = year;
    month = month;
    day = day;
  }
};
class Queue {
  AnimalNode* tail;
  AnimalNode* head;
  void enqueue();
  void dequeue();
};

void Queue::enqueue(AnimalNode& node) {
  AnimalNode newNode = node;
  if(this->tail == NULL) {
    this->tail = newNode;
  }
  if(this->head == NULL) {
    this->head = newNode;
  } else {
    newNode->nextAnimal = this->head;
    this->head = newNode;
  }

}


class AnimalShelter {
};
