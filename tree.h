#include <iostream>

using namespace std;

class Tree {
  int *array;
  int size;
 public:
  Tree();
  ~Tree();
  void insert(int);
  void swap(int*, int*);
  int search(int);
  void order(int);
  void print();
  void remove(int); 
 private:
};
