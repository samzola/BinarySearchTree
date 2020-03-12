#include <iostream>

using namespace std;

class Tree {
  int *array;
  int size;
  int root;
  int capacity;
 public:
  Tree(int);
  ~Tree();
  void insert(int);
  void swap(int*, int*);
  void search(int);
  void order(int);
  void print();
  void remove(int);
  bool inTree(int);
 private:
};
