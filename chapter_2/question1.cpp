#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
class Node {
public:
  int data;
  Node* next;

  //default constructor
  Node() { data = 0; next = NULL; }
  //parameterised constructor
  Node(int data) {
    this->data = data;
    this->next = NULL;
  }
};

//linked list class
class Linkedlist {
  Node* head;
public:
  //default
  Linkedlist() { head = NULL; }
  //functions
  void insertNode(int);
  void deleteNode(int);
  void printList();
  void makeUnrepeating();
};

void Linkedlist::insertNode(int data) {
  Node* newNode = new Node(data); 

  //assign head
  if (head == NULL) {
    head = newNode;
    return;
  }
  //traverse
  Node* temp = head;
  while (temp->next != NULL) { temp = temp->next; }
  temp->next = newNode;
}

void Linkedlist::deleteNode(int target) {
  Node *temp1 = head, *temp2 = NULL;
  int ListLen = 0;

  if (head == NULL) {
    std::cout << "empty list" <<
      std::endl;
    return;
  }
  //find length
  while (temp1 != NULL) {
    temp1 = temp1->next;
    ListLen++;
  }
  //check within linked list size
  if (ListLen < target) {
    std::cout << "Out of range" <<
      std::endl;
    return;
  }
  //declare temp
  temp1 = head;
  //delete head
  if (target == 1) {
    //update head
    head = head->next;
    delete temp1;
    return;
  }
  //traverse list
  while (target-- > 1) {
    temp2 = temp1;
    temp1 = temp1->next;
  }
  temp2->next = temp1->next;
  //del node
  delete temp1;
}
void Linkedlist::makeUnrepeating() {
  std::set<int> uniqueInts;
  Node *cursor = this->head;
  int position = 0;
  while (cursor != NULL) {
    int info = cursor->data;
    auto data = uniqueInts.find(info);
    position ++;
    //find does not work here at all bruh TODO
    if(uniqueInts.empty() != true && data != uniqueInts.end()) {
      this->deleteNode(*data);
    }
    uniqueInts.insert(cursor->data);
    cursor = cursor->next; 
  } 
}

void Linkedlist::printList() {
  Node* cursor = this->head;
  while (cursor != NULL) {
    std::cout << cursor->data << std::endl;
    cursor = cursor->next; 
  }
  return;
}
/*
std::map<int, int> Linkedlist::findMultiples(std::vector<int> conversion) {
  std::map<int, int> hash;
  bool array[128];
  for(int i = 0; i <= conversion.size(); i++) {
    int value = conversion[i];
    if(array[value]) {
      hash.insert({i, value});
    }
  }
  return hash;
}
*/
int main() {
  Linkedlist newList;
  newList.insertNode(1);
  newList.insertNode(1);
  newList.insertNode(3);
  newList.insertNode(19);
  newList.insertNode(123);  
  newList.printList();
  newList.makeUnrepeating();
  newList.printList();
  //makeUnrepeating(newList);
  //deleteMultiples(newList, findMultiples(linkedListConvert(newList)));
};
