#include <iostream>

class Node {
public:
  int data;
  Node* left;
  Node* right;
  int height;
  Node(int data, Node* l, Node* r, int h) : data(data), left(l), right(r), height(h) {}
};



int height(Node* node) {
  if(node == nullptr) {
    return 0;
  }
  return node->height;
}

void updateHeight(Node* node) {
  node->height = 1 + std::max(height(node->left), height(node->right));
}

Node* rotateLeft(Node* node) {
  Node* right = node->right;
  node->right = right->left;
  right->left = node;
  updateHeight(node);
  updateHeight(right);
  return right;
}

Node* rotateRight(Node* node) {
  Node* left = node->left;
  node->left = left->right;
  left->right = node;
  updateHeight(node);
  updateHeight(left);
  return left;
}

int balanceFactor(Node* node) {
  return height(node->right) - height(node->left);
}

Node* insert(Node* node, int data) {
  if(node == nullptr) {
    return new Node(data, nullptr, nullptr, 1);
  }

  if (data < node->data) {
    node->left = insert(node->left, data);
  } else {
    node->right = insert(node->right, data);
  }

  updateHeight(node);

  int balance = balanceFactor(node);
  if (balance == 2) {
    if (balanceFactor(node->right) < 0) {
      node->right = rotateRight(node->right);
    }
    return rotateLeft(node);
  }
  if (balance == -2) {
    if (balanceFactor(node->left) > 0) {
      node->left = rotateLeft(node->left);
    }
    return rotateRight(node);
  }
  return node;
}

int main() {
  return 0;
}
