#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include<time.h>
#include "table.h"


using namespace std;

Student* getStudent();

int main() {
  std::string line;
  vector<string> firsts;
  vector<string> lasts;
  ifstream firstsFile("firsts.txt");
  ifstream lastsFile("lasts.txt");

  srand(time(NULL));
  
  //got reading of lines -> vectors from stack overflow
  while (std::getline(firstsFile, line)) {
    firsts.push_back(line);
  }
  while (std::getline(lastsFile, line)) {
    lasts.push_back(line);
  }
  
  char input[50];
  Table studentTable(100);
  string rdmFirst;
  string rdmLast;

  while (true) {
    
    cout << "COMMANDS: "<< endl << "ADD: Create a new entry to the student list"
	 << endl << "PRINT: Prints all current entries in the student list"
	 << endl << "DELETE: Deletes speciied student from the list"
	 << endl << "RDMADD: Adds a user specified number of randomly generated students"
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
    //if RDMADD
    else if (strcmp(input,"RDMADD") == 0 || strcmp(input,"rdmadd") == 0) {
      cout << "How many students would you like to add? " << endl;
      cin.getline(input, 50, '\n');
      int rdmNum = atoi (input);
      for (int i = 0; i < rdmNum; i++) {
	rdmFirst = firsts[rand() % firsts.size()];
	rdmLast = lasts[rand() % lasts.size()];
	char temp1 = '0' + rand() % 5;
	char temp2 = '0' + rand() % 10;
	//stack overflow char to std::string
	string tempGPA = string(1, temp1) + "." + string(1, temp2);
	cout << tempGPA << endl;
	float rdmGPA = atof(tempGPA.c_str());
	cout << "Adding: " << rdmFirst << " " << rdmLast << " " << i + 1 << " " << rdmGPA << endl;
	studentTable.add(new Student((char*)rdmFirst.c_str(), (char*)rdmLast.c_str(), i + 1, rdmGPA));
      }
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






