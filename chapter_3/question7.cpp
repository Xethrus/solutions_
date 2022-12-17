#include <iostream>
#include <vector>
class Animal {
public:
  int year, month, day;
  Animal() {
    year = 0;
    month = 0;
    day = 0;
  }
  Animal(int year,int month,int day) {
    this->year = year;
    this->month = month;
    this->day = day;
  }
};
class Queue {
public:
  std::vector<Animal> animals;
  std::vector<Animal> dogs;
  std::vector<Animal> cats;
  void enqueue(Animal);
  Animal dequeue();
  
};

void Queue::enqueue(Animal animal) {
  animals.push_back(animal);
}

&Animal Queue::dequeue() {
  Animal temp = animals[0];
  animals.erase(animals.begin());
  return temp;
}


int main() {
  Queue shelter;
  shelter.enqueue(Animal(2022,3,23));
}
