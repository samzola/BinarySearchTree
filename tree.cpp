#include <iostream>
#include <climits>
#include <cmath>
#include "tree.h"

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
	break;
      }
      Node* newN = new Node();
      newN->left = 0;
      newN->right = 0;
      newN->parent = 0;
      newN->data = data;
      current->left = newN;
      size++;
      return;
    }
    else if (data > current->data) {
      if (current->right) {
	current = current->right;
	break;
      }
      Node* newN = new Node();
      newN->left = 0;
      newN->right = 0;
      newN->parent = 0;
      newN->data = data;
      current->right = newN;
      size++;
      return;
    }
  }
}

void Tree::swap(int *x, int *y) { //swap two nodes
  int temp = *x;
  *x = *y;
  *y = temp;
}

void Tree::order(int i) { //makes max heap
  int l = (2*i)+1; //left child
  int r = (2*i)+2; //right child
  int p = (i-1)/2;

  int current = i;

  /*if (array[i] > array[l]) {
    swap(&array[i], &array[l]);
    order(l);
  }

  if (array[i] > array[r]) {
    swap(&array[i], &array[r]);
    order(r);
  }*/
  
  /*int largest = i; //keeps track of largest node
  if (l < size && array[l] > array[i]) { //if left is larger than current node, make it largest
    largest = l;
  }
  if (r < size && array[r] > array[largest]) { //if right is larger than current, make it largest
    largest = r;
  }
  if (largest != i) { //if largest has changed
    swap(&array[i], &array[largest]); //swap positions
    order(largest); //recursively call heapify
    }*/
}

void Tree::print() { //prints main heap
  /*cout << endl;
  int num = 1; //keeps track of row
  int printed = 0; //keeps track of number printed for each row
  for (int i = 0; i < size; i++) { //for loop to run through each number
    if (num != 1) {
      cout << array[i] << "(" << array[(i-1)/2] << ")" << " "; //print numbers
    }
    else {
      cout << array[i] << " "; //print numbers
    }
    printed++;
    if (printed == num) { //keep printing until number printed in each row is max
      cout << endl; //move to next row
      num = num << 1; //reset num and printed
      printed = 0;
    }
  }
  cout << endl;*/
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

bool Tree::inTree(int k) {
  /*for (int i = 0; i < size; i++) {
    if (array[i] == k) {
      return true;
    }
  }
  return false;*/
}

void Tree::remove(int k) {
  /*int value = 0;
  if (inTree(k) == true) {
    for (int i = 0; i < size; i++) {
      if (array[i] == k) {
	swap(&array[i], &array[size - 1]);
	size--;
	order(i);
	//value = array[i];
      }
    }
    //order(value);
    //cout << value << ", " << last << endl;
    //swap(&value, &last);
    //cout << value << ", " << last << endl;
    //print();
    //size--;
  }
  else {
    cout << "The number " << k << " cannot be deleted, as it is not in the tree." << endl;
    }*/
}

void Tree::preSearch(int k) {
  search(root, k);
}
