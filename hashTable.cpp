#include <iostream>
#include <iomanip>
#include "table.h"

using namespace std;

Student* getStudent();

int main() {
  
  char input[50];
  Table studentTable(100);
  while (true) {
    
    cout << "COMMANDS: "<< endl << "ADD: Create a new entry to the student list"
	 << endl << "PRINT: Prints all current entries in the student list"
	 << endl << "DELETE: Deletes speciied student from the list"
	 << endl << "AVERAGE: Prints the average of all student GPAs"
	 << endl << "QUIT: Exits the program" << endl;
    cin.getline(input, 50, '\n');
    //if ADD, add new student
    if (strcmp(input,"ADD") == 0 || strcmp(input,"add") == 0) {
      studentTable.add(getStudent());
      cout << "Student added! " << endl;
    }
    //if PRINT, print all currently stored students
    else if (strcmp(input,"PRINT") == 0 || strcmp(input,"print") == 0) {
      studentTable.printTable();
    }
    //if DELETE, delete student from list
    else if (strcmp(input,"DELETE") == 0 || strcmp(input,"delete") == 0) {
      int delId;
      cout << "Enter the id of the student you would like to remove from the list: " << endl;
      cin.getline(input, 50, '\n');
      delId = atoi (input);
      studentTable.rmStudent(delId);
    }
    
    //if QUIT, exit program
    else if (strcmp(input,"QUIT") == 0 || strcmp(input,"quit") == 0) {
      break;
    }
    //else, cmd not recognized
    else if (strcmp(input,"QUIT") != 0 && strcmp(input,"quit") != 0
	     && strcmp(input,"DELETE") != 0 && strcmp(input,"delete") != 0 &&
	     strcmp(input,"PRINT") != 0 && strcmp(input,"print") != 0
	     && strcmp(input,"ADD") != 0 && strcmp(input,"add") != 0) {
      cout << "Command not recognized" << endl;
    }
  }
}

Student* getStudent() {
  char input[50];
  char firstname[50];
  char lastname[50];
  int studentid;
  float studentgpa;
  //change to cstring stuff
  cout << "Student's first name: ";
  cin.getline(firstname, sizeof(firstname), '\n');
  cout << "Student's last name: ";
  cin.getline(lastname, sizeof(lastname), '\n');
  cout << "Student's ID#: ";
  cin.getline(input, 50, '\n');
  studentid = atoi (input);
  cout << "Student's GPA: ";
  cin.getline(input, 50, '\n');
  studentgpa = atof (input);

  return new Student(firstname, lastname, studentid, studentgpa);
}






