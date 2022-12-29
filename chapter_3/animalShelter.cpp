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
    return species;
  }
}

class AnimalShelter {
public:
  Queue dogs;
  Queue cats;
  Queue both;
  
  void enqueueCat(std::string);
  void enqueueDog(std::string);
  std::string dequeueCat();
  std::string dequeueDog();
  std::string dequeueFirst();
};

void AnimalShelter::enqueueCat(std::string name) {
  this->cats.enqueue(name);
  this->both.enqueue(name);
}

void AnimalShelter::enqueueDog(std::string name) {
  this->dogs.enqueue(name);
  this->both.enqueue(name);
}

std::string AnimalShelter::dequeueCat() {
  std::string animal = this->cats.dequeue();
  std::cout << "==== " << animal << " ==== Has been adopted"
    << std::endl;
  return animal;
}

std::string AnimalShelter::dequeueDog() {
  std::string animal = this->dogs.dequeue();
  std::cout << "==== " << animal << " ==== Has been adopted"
    << std::endl;
  return animal;
}

std::string AnimalShelter::dequeueFirst() {
  std::string animal = this->both.dequeue();
  std::cout << "==== " << animal << " ==== Has been adopted"
    << std::endl;
  return animal;
}



int main() {
  AnimalShelter shelter;
  shelter.enqueueDog("moongman");
  shelter.enqueueCat("clarence");
  shelter.enqueueCat("clarence");
  shelter.dequeueCat();
  shelter.dequeueFirst();
  return 0;
}
