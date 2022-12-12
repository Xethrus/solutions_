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
  void deleteNthFromEnd(int);
  void printList();
  int getLength();
};

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
  int listLength = 0;
  Node* cursor = this->head;
  while (cursor != NULL) {
    listLength++;
    cursor = cursor->next;
  }
  return listLength;
}

void Linkedlist::deleteNthFromEnd(int fromBack) {
  int wantedDepth = this->getLength() - fromBack;
  this->deleteNode(wantedDepth); 
}

void Linkedlist::printList() {
  Node* cursor = this->head;
  while (cursor != NULL) {
    std::cout << cursor->data <<
      std::endl;
    cursor = cursor->next;
  }
}
int main() {
  Linkedlist listObject;
  listObject.insertNode(1);
  listObject.insertNode(2);
  listObject.insertNode(3);
  listObject.insertNode(4);
  listObject.insertNode(5);
  listObject.insertNode(6);
  listObject.deleteNthFromEnd(2);
  listObject.printList(); 
}

