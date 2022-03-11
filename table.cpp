//libraries
#include <iostream>
#include "table.h"

using namespace std;

Table::Table(int numBuckets){//constructor class
  this->numBuckets = numBuckets;
}

Table::~Table(){//destructor
  cout << "deletes something" << endl;
  //itterate over buckets in table, for each bucket delete each list inside it and each student object
}

void Table::printTable(){
  cout << "prints whole table" << endl;
  //itterate over buckets in table, for each bucket print each list inside it and each student object
}

void Table::add(Student* student){
  cout << "adds a student" << endl;
}

void Table::rmStudent(int studentID){
  cout << "removes a student" << endl;

}
