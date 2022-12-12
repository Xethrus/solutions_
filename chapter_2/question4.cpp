#include <iostream>

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
  void insertNode(int);
  void deleteNode(int);
  int getLength();
  int * getValues(int);
  void rebuildList(int *);
  void printList();
};
void Linkedlist::printList() {
  Node* cursor = this->head;
  while (cursor != NULL) {
    std::cout << cursor->data << std::endl;
    cursor = cursor->next;
  }  
  return;
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

void Linkedlist::deleteNode(int position) {
  Node *temp1 = head, *temp2 = NULL;
  int listSize = 0;
  if (head == NULL) { return; }
  while (temp1 != NULL) {
    temp1 = temp1->next;
    listSize++;
  }
  if (listSize < position) { return; }
  temp1 = head;
  if (position == 1) {
    head = head->next;
    delete temp1;
    return;
  }
  while (position-- > 1) {
    temp2 = temp1;
    temp1 = temp1->next;
  }
  temp2->next = temp1->next;
  delete temp1;
}
int Linkedlist::getLength() {
  int size = 0;
  Node* cursor = this->head;
  while (cursor != NULL) {
    size++;
    cursor = cursor->next;
  }
  return size;
}
//broken function
int * Linkedlist::getValues(int keyValue) {
  int length = this->getLength();
  int values[length];
  int counter = 0;
  Node* cursor = this->head;
  while (cursor != NULL && counter <= length) {
    counter++;
    values[counter] = cursor->data;  
  }  
  int lesser = 0;
  int greater = 0;
  for(int i = 0; i < length; i++) {
    if(values[i] < keyValue) {
      lesser++; 
    } else {
      greater++;
    }  
  }
  int lesserArray[lesser];
  int greaterArray[greater];
  int lesserCounter = 0;
  int greaterCounter = 0;
  for(int i = 0; i < length; i++) {
    if(values[i] < keyValue) {
      lesserArray[lesserCounter] = values[i];
      lesserCounter++;
    } else {
      greaterArray[greaterCounter] = values[i];
      greaterCounter++;
    }
  }
  for(int i = 0; i < lesser; i++) {
    values[i] = lesserArray[i];  
  }
  for(int i = lesser; i < greater + lesser; i++) {
    values[i] = greaterArray[i];
  }
  for(int i = 0; i < length; i++) {
    std::cout << values[i] << std::endl;
  }
  return values;
}
void Linkedlist::rebuildList(int * array){
  Node *cursor = this->head;
  //not able to access this array, something is broken in the implementation
  std::cout << array[0] << std::endl;
  int counter = 0;
  while (cursor != NULL) {
    //seg fault
    cursor->data = array[counter];
    cursor = cursor->next;
    counter++;  
  }
}

int main() {
  Linkedlist list;
  list.insertNode(1);
  list.insertNode(2);
  list.insertNode(3);
  list.insertNode(99);
  list.insertNode(5);
  list.insertNode(2);
  list.insertNode(7);
  list.insertNode(8);
  list.rebuildList(list.getValues(5));
  return 0;
}
