#include<iostream>
#include<vector>
#include<string.h>

using namespace std;

char input[50];

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
  /*
// Create a vector containing integers
    std::vector<int> v = { 7, 5, 16, 8 };
 
    // Add two more integers to vector
    v.push_back(25);
    v.push_back(13);
 
    // Print out the vector
    std::cout << "v = { ";
    for (int n : v) {
        std::cout << n << ", ";
    }
    std::cout << "}; \n";
   */
  while (true) {
      //initialize empty student vector
      //print possible cmds
      cout << "COMMANDS: "<< endl << "ADD: Create a new entry to the student list"
	   << endl << "PRINT: Prints all current entries in the student list"
	   << endl << "DELETE: Deletes speciied student from the list"
	   << endl << "QUIT: Exits the program" << endl;
      cin.getline(input, 50, '\n');
      //if ADD, add new student
      if (strcmp(input,"ADD") == 0 || strcmp(input,"add") == 0) {
	cout << "ADD" << endl;
      }
      //if PRINT, print all currently stored students
      else if (strcmp(input,"PRINT") == 0 || strcmp(input,"print") == 0) {
	cout << "PRINT" << endl;
      }
      //if DELETE, delete student from list
      else if (strcmp(input,"DELETE") == 0 || strcmp(input,"delete") == 0) {
	cout << "DELETE" << endl;
      }
      //if QUIT, exit program
      else if (strcmp(input,"QUIT") == 0 || strcmp(input,"quit") == 0) {
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


