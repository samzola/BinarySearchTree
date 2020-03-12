#include <iostream>

using namespace std;

class Tree {
  struct Node {
    Node* parent;
    Node* left;
    Node* right;
    int data;
  };
  int size;
  Node* root;
 public:
  Tree();
  ~Tree();
  void insert(int);
  void swap(int*, int*);
  void search(Node*, int);
  void order(int);
  void print(Node*, int);
  void remove(int);
  Node* inTree(Node*, int);
  void move(Node*);
  void preSearch(int);
  void prePrint();
 private:
};
