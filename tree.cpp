#include <iostream>
#include <climits>
#include <cmath>
#include "tree.h"

#define COUNT 5

Tree::Tree() {
  size = 0;
  root = 0;
}

Tree::~Tree() {}

void Tree::insert(int data) {
  if (root == 0) {
    root = new Node();
    root->left = 0;
    root->right = 0;
    root->parent = 0;
    root->data = data;
    size++;
    return;
  }

  Node* current = root;
  while (true) {
    if (data <= current->data) {
      if (current->left) {
	current = current->left;
	continue;
      }
      Node* newN = new Node();
      newN->left = 0;
      newN->right = 0;
      newN->parent = current;
      newN->data = data;
      current->left = newN;
      size++;
      return;
    }
    else if (data > current->data) {
      if (current->right) {
	current = current->right;
	continue;
      }
      Node* newN = new Node();
      newN->left = 0;
      newN->right = 0;
      newN->parent = current;
      newN->data = data;
      current->right = newN;
      size++;
      return;
    }
  }
}

void Tree::print(Node* root, int s) { //prints main heap
  if (root == NULL) {
    return;
  }
  s += COUNT;
  print(root->right, s);
  cout << endl;
  for (int i = COUNT; i < s; i++) {
    cout << " ";
  }
  cout << root->data << '\n';
  print(root->left, s);
}

void Tree::search(Node* root, int k) {
  if (root->data == k) {
    cout << "The number " << k << " is in the tree." << endl;
    return;
  }
  else if (root->data > k) {
    if (root->left) {
      root = root->left;
      search(root, k);
    }
    else {
      cout << "The number " << k << " is not in the tree." << endl;
    }
  }
  else if (root->data < k) {
    if (root->right) {
      root = root->right;
      search(root, k);
    }
    else {
      cout << "The number " << k << " is not in the tree." << endl;
    }
  }
}

Tree::Node* Tree::inTree(Node* root, int k) {
  if (root->data == k) {
    return root;    
  }
  if (root->left != 0) {
    Node* node = inTree(root->left, k);
    if (node != 0) {
      return node;
    }
  }
  if (root->right != 0) {
    Node* node = inTree(root->right, k);
    if (node != 0) {
      return node;
    }
  }
  else {
    return 0;
  }
}

void Tree::remove(int k) {
  Node* d = inTree(root, k);

  if (d == 0) {
    cout << k << " is not in the tree. Cannot delete." << endl;
    return;
  }
  move(d);
  size--;
}

void Tree::move(Node* root) {
  if (root->parent != 0) {
    root->parent->data = root->data;
  }
  if (root->right != 0) {
    move(root->right);
  }
  else {
    root->parent->right = 0;
    delete root;
  }
}

void Tree::preSearch(int k) {
  search(root, k);
}

void Tree::prePrint() {
  print(root, 0);
}
