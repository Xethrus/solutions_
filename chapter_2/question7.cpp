#include <iostream>
#include <vector>

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
  bool isPaldrom();
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

bool Linkedlist::isPaldrom() {
  Node* cursor = head;
  std::vector<int> vector;
  while (cursor != NULL) {
    vector.push_back(cursor->data);
    cursor = cursor->next;
  }
  int endPlace = vector.size();
  int midpoint;
  if ((endPlace % 2) == 0) {
    midpoint = endPlace/2;
  } else {
    midpoint = (endPlace/2) + 1;
  }
  endPlace = endPlace - 1;
  for(int i = 0; i <= midpoint; i++) {
    if( vector[i] != vector[endPlace] ) {
      std::cout << "false bro" << std::endl;
      return false;
    }
    endPlace--;
  } 
  std::cout << "true bro" << std::endl;
  return true;
}
int main() {
  Linkedlist list;
  list.insertNode(1);
  list.insertNode(1);
  list.insertNode(1);
  list.insertNode(1);
  list.insertNode(4);
  list.insertNode(1);
  list.insertNode(1);
  list.insertNode(1);
  list.insertNode(1);
  list.isPaldrom();
}




