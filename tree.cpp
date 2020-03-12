#include <iostream>
#include <climits>
#include "tree.h"

Tree::Tree(int cap) {
  size = 0;
  root = 0;
  capacity = cap;
  array = new int[cap];
}

Tree::~Tree() {}

void Tree::insert(int k) {
  if (size == capacity) {
    cout << "Cannot insert, tree is full." << endl;
  }

  size++;
  int i = size - 1;
  array[i] = k;
  order(i);
}

void Tree::swap(int *x, int *y) { //swap two nodes
  int temp = *x;
  *x = *y;
  *y = temp;
}

void Tree::order(int i) { //makes max heap
  int l = (2*i)+1; //left child
  int r = (2*i)+2; //right child
  int largest = i; //keeps track of largest node
  if (l < size && array[l] > array[i]) { //if left is larger than current node, make it largest
    largest = l;
  }
  if (r < size && array[r] > array[largest]) { //if right is larger than current, make it largest
    largest = r;
  }
  if (largest != i) { //if largest has changed
    swap(&array[i], &array[largest]); //swap positions
    order(largest); //recursively call heapify
  }
}

void Tree::print() { //prints main heap
  cout << endl;
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
  cout << endl;
}

void Tree::search(int k) {
  for (int i = 0; i < size; i++) {
    if (array[i] == k) {
      cout << "The number " << k << " has been found at index " << i << "." << endl;
      return;
    }
  }
  cout << "The number " << k << " is not in the tree." << endl;
}

bool Tree::inTree(int k) {
  for (int i = 0; i < size; i++) {
    if (array[i] == k) {
      return true;
    }
  }
  return false;
}

void Tree::remove(int k) {
  int value = 0;
  if (inTree(k) == true) {
    for (int i = 0; i < size; i++) {
      if (array[i] == k) {
	array[i] = 9999;
	value = array[i];
      }
    }
    order(value);
    //cout << value << ", " << last << endl;
    //swap(&value, &last);
    //cout << value << ", " << last << endl;
    print();
    size--;
    int x = array[0];
    order(x);
  }
  else {
    cout << "The number " << k << " cannot be deleted, as it is not in the tree." << endl;
  }
}
