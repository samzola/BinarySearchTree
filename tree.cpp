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

void Tree::insert(int data) { //adds nodes to the tree. Credit: Tejash Panda
  if (root == 0) { //if there are no nodes
    root = new Node(); //make the root node
    root->left = 0;
    root->right = 0;
    root->parent = 0;
    root->data = data;
    size++;
    return;
  }

  Node* current = root;
  while (true) {
    if (data <= current->data) { //if the inserted data is smaller than the current data
      if (current->left) { //if current has a left node
	current = current->left; //make current its left node
	continue; //skip iteration
      }
      Node* newN = new Node(); //make a new node to left of current
      newN->left = 0;
      newN->right = 0;
      newN->parent = current;
      newN->data = data;
      current->left = newN;
      size++;
      return;
    }
    else if (data > current->data) { //if the inserted data is larger than the current data
      if (current->right) { //if current has a right node
	current = current->right; //make current its right node
	continue; //skip iteration
      }
      Node* newN = new Node(); //make a new node right of the current
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

void Tree::print(Node* root, int s) { //prints tree
  if (root == NULL) { //if empty
    return; //dont print
  }
  s += COUNT; //add 5 spaces
  print(root->right, s); //print one row
  cout << endl;
  for (int i = COUNT; i < s; i++) { //print spaces
    cout << " ";
  }
  cout << root->data << '\n';
  print(root->left, s); //recursively print
}

void Tree::search(Node* root, int k) { //searches for a number
  if (root->data == k) { //if the number is the root
    cout << "The number " << k << " is in the tree." << endl; //tell user
    return;
  }
  else if (root->data > k) { //if the root is bigger than the number
    if (root->left) { //if the root has a left node
      root = root->left; //go left
      search(root, k); //recursively search
    }
    else { //if the root doesn't have a left node
      cout << "The number " << k << " is not in the tree." << endl; //tell user
    }
  }
  else if (root->data < k) { //if the root is smaller than the number
    if (root->right) { //if the root has a right node
      root = root->right; //go right
      search(root, k); //recursively search
    }
    else { //if the root doesn't have a right node
      cout << "The number " << k << " is not in the tree." << endl; //tell user
    }
  }
}

Tree::Node* Tree::remove(Node* root, int k) { //deletes a node
  if (root == NULL) { //if tree is empty, don't remove
    return root;
  }
  else if (k < root->data) { //if number is less than root
    root->left = remove(root->left, k); //recursively remove with left child
  }
  else if (k > root->data) { //if number is greater than root
    root->right = remove(root->right, k); //recursively remove with right child
  }
  else { //if number is equal to root
    if(root->left == NULL && root->right == NULL) { //if no children
      delete root; //delete root and make null
      root = NULL;
    }
    else if(root->left == NULL) { //if no left child
      Node* temp = root; //replace with right
      root = root->right;
      delete temp;
    }
    else if(root->right == NULL) { //if no right child
      Node* temp = root; //replace with left
      root = root->left;
      delete temp;
    }
    else { //if 2 children
      Node* temp = min(root->right); //find min number
      root->data = temp->data; //remove
      root->right = remove(root->right,temp->data);
    }
  }
  return root;
}

Tree::Node* Tree::min(Node* root) { //finds minimum value in tree
  while(root->left != NULL) {
    root = root->left;
  }
  return root;
}

void Tree::preSearch(int k) { //allows search to call root
  search(root, k);
}

void Tree::prePrint() { //allows print to call root
  print(root, 0);
}

void Tree::preRemove(int k) { //allows print to call root
  remove(root, k);
}
