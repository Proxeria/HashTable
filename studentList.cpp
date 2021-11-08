#include<iostream>

using namespace std;

string input;

struct Student {
  char firstName[10];
  char lastName[10];
  int id;
  float gpa;
};



struct Student getStudent() {
  Student newStudent;
  cout << "Student's first name: ";
  cin >> newStudent.firstName;
  cout << "Student's last name: ";
  cin >> newStudent.lastName;
  cout << "Student's ID#: ";
  cin >> newStudent.id;
  cout << "Student's GPA: ";
  cin >> newStudent.gpa;
  cout << newStudent.firstName << " " << newStudent.lastName << " ID:"
       << newStudent.id << " GPA:" << newStudent.gpa << endl;

    return newStudent;
}

int main() {
  while (true) {
      //initialize empty student vector
      //print possible cmds
      cout << "COMMANDS: "<< endl << "ADD: Create a new entry to the student list"
	   << endl << "PRINT: Prints all current entries in the student list"
	   << endl << "DELETE: Deletes speciied student from the list"
	   << endl << "QUIT: Exits the program" << endl;
      cin >> input;
      //if ADD, add new student
      if (input == "ADD" || input == "add") {
	cout << "ADD" << endl;
      }
      //if PRINT, print all currently stored students
      else if (input == "PRINT" || input == "print") {
	cout << "PRINT" << endl;
      }
      //if DELETE, delete student from list
      else if (input == "DELETE" || input == "delete") {
	cout << "DELETE" << endl;
      }
      //if QUIT, exit program
      else if (input == "QUIT" || input == "quit") {
	cout << "QUIT" << endl;
	break;
      }
      //else, cmd not recognized
      else {
	cout << "Command not recognized" << endl;
      }
    }



  return 0;
}
//this thing


