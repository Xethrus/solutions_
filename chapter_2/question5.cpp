#include <iostream>
#include <cmath>

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

class Linkedlist {
  Node* head;
  public:
  Linkedlist() { head = NULL; }
  int arraySize;
  void insertNode(int);
  void printList();
  float get3DigitNumber();
  void intToNode(int); 
  void buildLinked(int *);
  int * intToArray(int);
  int * cycleArray(int *);
  //int reduceInts(int);
};
int * Linkedlist::intToArray(int number) {
  int divisor = 10;
  int count = 0;
  int temp = number;
  while (number / divisor > 0) {
    number = number / divisor;
    count++;
  }
  //lookout for array being too small
  count = count + 1;
  arraySize = count;
  int *array = new int[count]; 
  for (int i = 1; i <= count + 1; i++) {
    int power = std::pow(divisor, i);
    array[i-1] = (temp % power);
  }
  int size = sizeof(array)/ 4;
  std::cout << "size: " << size << std::endl;
  for (int i = 0; i < size; i++) {
    std::cout << "array: " << array[i] << std::endl;
  }
  return array;
}
int reduceInts(int value) {
  while (value / 10 > 0) {
    value = value / 10;
  }
  return value;
}
int * Linkedlist::cycleArray(int * array) {
  std::cout << array << std::endl;
  int size = arraySize; 

  for(int i = 0; i < size; i++) {
    std::cout << array[i] << std::endl;
    array[i] = reduceInts(array[i]);
  }
  for (int i = 0; i < size; i++) {
    std::cout << "array2: " << array[i] << std::endl;
  }
  return array;
}
void Linkedlist::buildLinked(int * array) {
  int size = arraySize; 
  for(int i = 0; i < size; i++) {
      insertNode(array[i]);
  }
}
void Linkedlist::insertNode(int data) {
  Node* newNode = new Node(data);
  if (head == NULL) {
    head = newNode;
    return;
  }
  Node* temp = head;
  while (temp->next != NULL) { temp = temp->next; }
  temp->next = newNode;
}
int giveValueZeroes(int key, int power) {
  int multiplier = std::pow(10, power);
  key = multiplier * key;
  return key;
}
float Linkedlist::get3DigitNumber() {
  Node* cursor = this->head;
  int value1 = 0;
  int value2 = 0;
  for(int i = 0; i  < 6; i++) {
    if ( i < 3 ) {
      value1 += giveValueZeroes(cursor->data, i);
    }
    if ( i >= 3 && i < 6) {
      value2 += giveValueZeroes(cursor->data, i-3);
    }
    cursor = cursor->next;
  }
  float finalValue = value1 + value2;
  return finalValue;
}
void Linkedlist::printList() {
  Node* cursor = head;
  if (cursor == NULL) {
    std::cout << "cursor is null" << std::endl;
  }
  while (cursor != NULL) {
    std::cout << cursor->data << std::endl;
    cursor = cursor->next;
  }
}
int main() {
  Linkedlist list;
  list.insertNode(1);
  list.insertNode(2);
  list.insertNode(3);
  list.insertNode(4);
  list.insertNode(5);
  list.insertNode(6);
  Linkedlist list2;
  list2.buildLinked(list2.cycleArray(list2.intToArray(list.get3DigitNumber())));
  list2.printList();
}
