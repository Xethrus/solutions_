#include <iostream>

class Node {
public:
  int data;
  Node* next;
};

void push(Node** head_ref, int data) {
  Node* ptr1 = new Node();
  ptr1->data = data;
  ptr1->next = *head_ref;

  if (*head_ref != NULL) {
    Node* temp = *head_ref;
    while (temp->next != *head_ref) {
      temp = temp->next;
      temp->next = ptr1;
    }
  } else {
    ptr1->next = ptr1;
  }
  *head_ref = ptr1;
}

void printList(Node* head) {
  Node* temp = head;
  if (head != NULL) {
    do {
      std::cout << temp->data << std::endl;
      temp = temp->next;
    } while (temp != head);
  }
}

void deleteNode(Node** head, int key) {
  if (*head == NULL) {
    return;
  }
  if ((*head)->data == key && (*head)->next == *head) {
    free(*head);
    *head = NULL;
    return;
  }

  Node *last = *head, *d;
  if ((*head)->data == key) {
    while (last->next != *head) {
      last = last->next;
    }
    last->next = (*head)->next;
    free(*head);
    *head = last->next;
    return;
  }
  while (last->next != *head && last->next->data != key) {
    last = last->next;
  }
  if (last->next->data == key) {
    d = last-next;
    last->next = d->next;
    free(d);
  } else {
    std::cout << "key not found" << std::endl;
  }
}

int main() {
  Node* head = NULL;
  push(&head, 2);
  push(&head, 5);
  push(&head, 7);
  push(&head, 8);
  push(&head, 10);
  
  printList(head);
  deleteNode(&head, 8);
  return 0;
}
