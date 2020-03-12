#include <iostream>
#include <string.h>
#include <cstdlib>
#include <fstream>
#include "tree.h"

using namespace std;

int main() {
  Tree t = Tree();
  bool running = true;
  char* input = new char[15];
  char* conOrFile = new char[15];
  while (running == true) {
    cout << "Please enter a command (add, delete, print, search, or quit)." << endl;
    cin.get(input, 15);
    cin.clear();
    cin.ignore(1000000, '\n');
    if (strcmp(input, "add") == 0) {
      cout << "Please enter how you would like to input your numbers (console or file)." << endl; //ask how they want to input
      char *method = new char[10];
      char *in = new char[100];
      cin.getline(method, 10, '\n');
      if (strcmp("console", method) == 0) { //if they say console, ask user to input numbers
	cout << "Please enter values with spaces between each value." << endl;
	cin.getline(in, 100, '\n'); //read in the numbers
	char *token = strtok(in, " "); //separate the numbers into tokens
	while (token != NULL) {
	  int token2 = atoi(token); //turn token into int from char*
	  t.insert(token2); //insert int token into tree
	  token = strtok(NULL, " "); //keep going through numbers
	}
      }
      else if (strcmp("file", method) == 0) { //if they say file, ask for file name
	cout << "Please enter the name of the file." << endl;
	char *fileI = new char[100];
	cin.get(fileI, 100, '\n'); //read in file name
	streampos size;
	ifstream file(fileI, ios::in | ios::binary | ios::ate);
	if (file.is_open()) {
	  size = file.tellg();
	  file.seekg(0, ios::beg); //search for the file and read it
	  file.read(input, size);
	  file.close();
	  char *token = strtok(input, " "); //separate numbers into tokens
	  while (token != NULL) {
	    int token2 = atoi(token); //turn token into int from char*
	    t.insert(token2); //insert int token into tree
	    token = strtok(NULL, " "); //keep going through numbers
	  }
	}
      }
    }
    else if (strcmp(input, "delete") == 0) {
      cout << "Please enter the number you would like to delete." << endl;
      char *delNum = new char[100];
      cin.getline(delNum, 100, '\n');
      char *Dtok = strtok(delNum, " ");
      int deleter = atoi(Dtok);
      //t.remove(deleter);
    }
    else if (strcmp(input, "print") == 0) {
      //t.print();
    }
    else if (strcmp(input, "search") == 0) {
      cout << "Please enter the number you would like to search for." << endl;
      char *searchNum = new char[100];
      cin.getline(searchNum, 100, '\n');
      char *tok = strtok(searchNum, " ");
      int searcher = atoi(tok);
      t.preSearch(searcher);
    }
    else if (strcmp(input, "quit") == 0) {
      running = false;
    }
    else {
      cout << "Invalid command, please try again." << endl;
    }
  }
}
