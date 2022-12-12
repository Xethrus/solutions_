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
  int listLength;
  Linkedlist() { head = NULL; }
  void insertNode(int);
  void printList();
  int updateLength();
  std::vector<int> arrangeValues(int); 
  void reorgList(std::vector<int>);
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

void Linkedlist::printList() {
  Node* cursor = head;
  while (cursor != NULL) {
    std::cout << cursor->data <<
      std::endl;
    cursor = cursor->next;
  }
  return;
}

int Linkedlist::updateLength() {
  Node* cursor = head;
  int size = 0;
  while (cursor != NULL) {
    size++;
    cursor = cursor->next;
  }
  return size;
}

std::vector<int> Linkedlist::arrangeValues(int key) {
  std::vector<int> values;
  std::vector<int> lesser;
  std::vector<int> greater;
  Node* cursor = head;
  while (cursor != NULL) {
    if (cursor->data < key) {
      lesser.push_back(cursor->data);
      cursor = cursor->next;
    } else {
      greater.push_back(cursor->data);
      cursor = cursor->next;
    }
  }
  for(int i = 0; i < lesser.size(); i++) {
    values.push_back(lesser[i]);
  }
  values.push_back(key);
  for(int i = 0; i < greater.size(); i++) {
    values.push_back(greater[i]);
  }
  return values;
}
void Linkedlist::reorgList(std::vector<int> order) {
  Node* cursor = this->head;
  int counter = 0;
  std::cout << order[counter] << std::endl;
  while (cursor != NULL) {
    cursor->data = order[counter];
    //std::cout << "cursor->data: " << cursor->data << std::endl;
    //std::cout << "order[counter]: " << order[counter] >> std::endl;
    counter++;
    cursor = cursor->next;
  }
  return;
}

int main() {
  Linkedlist list;
  list.insertNode(1);
  list.insertNode(3);
  list.insertNode(1);
  list.insertNode(9);
  list.insertNode(1);
  list.insertNode(4);
  list.insertNode(3);
  list.insertNode(2);
  list.printList();
  list.reorgList(list.arrangeValues(4));  
  list.printList();
  return 0;  
}
