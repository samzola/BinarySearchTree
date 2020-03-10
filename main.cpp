#include <iostream>
#include <string.h>
#include <cstdlib>

using namespace std;

int main() {
  bool running = true;
  char* input = new char[15];
  char* conOrFile = new char[15];
  while (running == true) {
    cout << "Please enter a command (add, delete, print, search, or quit)." << endl;
    cin.get(input, 15);
    cin.clear();
    cin.ignore(1000000, '\n');
    if (strcmp(input, "add") == 0) {
      cout << "Would you like to add via console or file?" << endl;
      cin.get(conOrFile, 15);
      cin.clear();
      cin.ignore(1000000, '\n');
      if (strcmp(conOrFile, "console") == 0) {
	cout << "add from console" << endl;
      }
      else if (strcmp(conOrFile, "file") == 0) {
	cout << "add from file" << endl;
      }
      else {
        cout << "Invalid command, please try again." << endl;
      }
    }
    else if (strcmp(input, "delete") == 0) {
      cout << "delete" << endl;
    }
    else if (strcmp(input, "print") == 0) {
      cout << "print" << endl;
    }
    else if (strcmp(input, "search") == 0) {
      cout << "search" << endl;
    }
    else if (strcmp(input, "quit") == 0) {
      running = false;
    }
    else {
      cout << "Invalid command, please try again." << endl;
    }
  }
}
