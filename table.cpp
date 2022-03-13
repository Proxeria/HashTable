//libraries
#include <iostream>
#include "table.h"

using namespace std;

Table::Table(int numBuckets){//constructor class
  this->numBuckets = numBuckets;
  buckets = new std::list<Student*>[numBuckets];
}

Table::~Table(){//destructor
  cout << "deletes something" << endl;
  //itterate over buckets in table, for each bucket delete each list inside it and each student object
  for (int i = 0; i < numBuckets; i++) {
    //delete student from each item in this bucket list
    for (auto it = buckets[i].begin(); it != buckets[i].end(); it++) {
      delete *it;
    }
  }
}

void Table::printTable(){
  cout << "prints whole table" << endl;
  //itterate over buckets in table, for each bucket print each list inside it and each student object
  for (int i = 0; i < numBuckets; i++) {
    //delete student from each item in this bucket list
    for (auto it = buckets[i].begin(); it != buckets[i].end(); it++) {
      cout << (*it)->getFirstname() << " ";
      cout << (*it)->getLastname() << " ";
      cout << (*it)->getStudentID() << " ";
      cout << (*it)->getGPA() << " ";
      cout << endl;
    }
  }
}

void Table::add(Student* student){
  int bucketID = hash(student->getStudentID());
  buckets[bucketID].push_back(student);
  cout << "adds a student" << endl;
}



void Table::rmStudent(int studentID){
  cout << "removes a student" << endl;

}

int Table::hash(int studentID){
  cout << "hashes a thing" << endl;
  return (studentID % this->numBuckets);
}
