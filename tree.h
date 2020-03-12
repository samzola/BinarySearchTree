#include <iostream>

using namespace std;

class Tree {
  struct Node { //nodes in the tree
    Node* parent;
    Node* left;
    Node* right;
    int data;
  };
  int size;
  Node* root;
 public:
  Tree(); //constructor
  ~Tree(); //destructor
  void insert(int); //add nodes
  void search(Node*, int); //search for a node
  void print(Node*, int); //print a node
  Node* remove(Node*, int); //delete a node
  Node* min(Node*); //finds min number in tree
  void preSearch(int); //allows search to call root
  void prePrint(); //allows print to call root
  void preRemove(int); //allows remove to call root
 private:
};
