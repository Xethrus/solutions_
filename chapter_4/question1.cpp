include <iostream>

class Node {
  int data;
  Node* left_child;
  Node* right_child;
  Node(int data) : data(data), left_child(nullptr), right_child(nullptr) {}
};

class BinaryTree {
  Node* root;
  BinaryTree() : root(nullptr) {}

  void insertNode(int);
  int getLeftHeight();
  int getRightHeight();
};
int BinaryTree::getRightHeight() {
  Node* cursor = root;
  int count = 1;
  if(cursor->right_child) {
    cursor = cursor->right_child;
    while(cursor->right_child || cursor->right_child) {  
      if(cursor->right_child) {
        cursor = cursor->right_child;
      } else {
        cursor = cursor->left_child;
      }
      count++;
    }
  }
  return count;
}
int BinaryTree::getLeftHeight() {
  Node* cursor = root;
  int count = 1;
  if(cursor->left_child) {
    cursor = cursor->left_child;
    while(cursor->right_child || cursor->left_child) {
      if(cursor->right_child) {
        cursor = cursor->right_child;
      } else {
        cursor = cursor->left_child;
      }
      count++;
    }
  }
  return count;
}
void BinaryTree::insertNode(int data) {
  Node* newNode = new Node(data);
  Node* cursor = root;
  if(!root) {
    root = new Node(data);
  } else {
    if(this.getLeftHeight() > this.getRightHeight()) {
      //left heigh is greater
      //add to right
      if(cursor->right_child) {
        cursor = cursor->right_child;
        while(cursor->right_child || cursor->left_child) {
          if(cursor->right_child) {
            cursor = cursor->right_child;  
          }
          if(cursor->left_child) {
            cursor = cursor->right_child;
          }
        } else {
          if(!cursor->left_child) {
            cursor->left_child = newNode;
            return;
          }
          if(!cursor->right_child) {
            cursor->right_child = newNode;
            return;
          }
        }
      } else {
        cursor->right_child = newNode;
        return;
      }
    } else {
      if(cursor->left_child) {
        cursor = cursor->left_child;
        while(cursor->right_child || cursor->left_child) {
          if(cursor->right_child) {
            cursor = cursor->right_child;  
          }
          if(cursor->left_child) {
            cursor = cursor->right_child;
          }
        } else {
          if(!cursor->left_child) {
            cursor->left_child = newnode;
            return;
          }
          if(!cursor->right_child) {
            cursor->right_child = newnode;
            return;
          }
        }
      } else {
        cursor->left_child = newnode;
        return;
      }
    }
  }
}

int main() {
  return 0;
}
