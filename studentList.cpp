#include<iostream>
#include<vector>
#include<string.h>

using namespace std;

/*
#include<bits/stdc++.h>
using namespace std;
 
class Hash
{
    int BUCKET;    // No. of buckets
 
    // Pointer to an array containing buckets
    list<int> *table;
public:
    Hash(int V);  // Constructor
 
    // inserts a key into hash table
    void insertItem(int x);
 
    // deletes a key from hash table
    void deleteItem(int key);
 
    // hash function to map values to key
    int hashFunction(int x) {
        return (x % BUCKET);
    }
 
    void displayHash();
};
 
Hash::Hash(int b)
{
    this->BUCKET = b;
    table = new list<int>[BUCKET];
}
 
void Hash::insertItem(int key)
{
    int index = hashFunction(key);
    table[index].push_back(key);
}
 
void Hash::deleteItem(int key)
{
  // get the hash index of key
  int index = hashFunction(key);
 
  // find the key in (index)th list
  list <int> :: iterator i;
  for (i = table[index].begin();
           i != table[index].end(); i++) {
    if (*i == key)
      break;
  }
 
  // if key is found in hash table, remove it
  if (i != table[index].end())
    table[index].erase(i);
}
 
// function to display hash table
void Hash::displayHash() {
  for (int i = 0; i < BUCKET; i++) {
  cout << i;
    for (auto x : table[i])
    cout << " --> " << x;
    cout << endl;
  }
}
 
// Driver program
int main()
{
  // array that contains keys to be mapped
  int a[] = {15, 11, 27, 8, 12};
  int n = sizeof(a)/sizeof(a[0]);
 
  // insert the keys into the hash table
  Hash h(7);   // 7 is count of buckets in
               // hash table
  for (int i = 0; i < n; i++)
    h.insertItem(a[i]); 
 
  // delete 12 from hash table
  h.deleteItem(12);
 
  // display the Hash table
  h.displayHash();
 
  return 0;
}
 */
struct Student {
  char firstName[10];
  char lastName[10];
  int id;
  float gpa;
};



struct Student getStudent() {
  char input[50];
  Student newStudent;
  //change to cstring stuff
  cout << "Student's first name: ";
  cin.getline(newStudent.firstName, sizeof(newStudent.firstName), '\n');
  cout << "Student's last name: ";
  cin.getline(newStudent.lastName, sizeof(newStudent.lastName), '\n');
  cout << "Student's ID#: ";
  cin.getline(input, 50, '\n');
  newStudent.id = atoi (input);
  cout << "Student's GPA: ";
  cin.getline(input, 50, '\n');
  newStudent.gpa = atof (input);
  
  return newStudent;
}

int main() {
  char input[50];
  
  std::vector<Student> students; //vector of Student named students
           
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
	students.push_back(getStudent());
	cout << "Student added! " << endl;
      }
      //if PRINT, print all currently stored students
      else if (strcmp(input,"PRINT") == 0 || strcmp(input,"print") == 0) {
	for (Student  thisStudent: students) {
	  std::cout << thisStudent.firstName << " " << thisStudent.lastName << ", " << thisStudent.id << ", " << ("%.2f", thisStudent.gpa) << endl;
	}
      }
      //if DELETE, delete student from list
      else if (strcmp(input,"DELETE") == 0 || strcmp(input,"delete") == 0) {
	int delId;
	cout << "Enter the id of the student you would like to remove from the list: " << endl;
	cin.getline(input, 50, '\n');
	delId = atoi (input);
	vector<Student>::iterator it;
	for (it = students.begin(); it != students.end(); it++) {
	  if (delId == it->id) {
	    students.erase(it);
	  }
	}
      }
      //if QUIT, exit program
      else if (strcmp(input,"QUIT") == 0 || strcmp(input,"quit") == 0) {
	break;
      }
      //else, cmd not recognized
      else if (strcmp(input,"QUIT") != 0 && strcmp(input,"quit") != 0 && strcmp(input,"DELETE") != 0 && strcmp(input,"delete") != 0 &&
	       strcmp(input,"PRINT") != 0 && strcmp(input,"print") != 0 && strcmp(input,"ADD") != 0 && strcmp(input,"add") != 0) {
	cout << "Command not recognized" << endl;
      }
    }
  return 0;
}
//this thing


