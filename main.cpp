/*
 * Author: Sam Zola
 * Date: 3/12/20
 * Program: This program allows the user to add, remove, delete, and search a binary search tree.
 */


#include <iostream>
#include <string.h>
#include <cstdlib>
#include <fstream>
#include "tree.h"

using namespace std;

int main() {
  Tree t = Tree(); //initialize the tree
  bool running = true; //keeps track of if program is running
  char* input = new char[15];
  char* conOrFile = new char[15];
  while (running == true) {
    //ask user to enter command
    cout << "Please enter a command (add, delete, print, search, or quit)." << endl;
    cin.get(input, 15); //read in command
    cin.clear();
    cin.ignore(1000000, '\n');
    if (strcmp(input, "add") == 0) { //if they want to add
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
    else if (strcmp(input, "delete") == 0) { //if they type "delete"
      //ask what they want to delete
      cout << "Please enter the number you would like to delete." << endl;
      char *delNum = new char[100];
      cin.getline(delNum, 100, '\n'); //read in input
      char *Dtok = strtok(delNum, " ");
      int deleter = atoi(Dtok);
      t.preRemove(deleter); //remove using inputted number
    }
    else if (strcmp(input, "print") == 0) { //if they enter "print"
      t.prePrint(); //print
    }
    else if (strcmp(input, "search") == 0) { //if they enter "search"
      //ask what they want to search for
      cout << "Please enter the number you would like to search for." << endl;
      char *searchNum = new char[100];
      cin.getline(searchNum, 100, '\n'); //read in input
      char *tok = strtok(searchNum, " ");
      int searcher = atoi(tok);
      t.preSearch(searcher); //searhc for inputted number
    }
    else if (strcmp(input, "quit") == 0) { //if they enter quit
      running = false; //quit
    }
    else {
      cout << "Invalid command, please try again." << endl;
    }
  }
}
