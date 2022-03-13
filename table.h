//header guards
#ifndef TABLE_H
#define TABLE_H

//all the libararies
#include <iostream>
#include <cstring>
#include <list>
#include "Student.h"

using namespace std;

class Table{
 public:
  Table(int numBuckets);
  ~Table();
  void add(Student* student);
  void rmStudent(int studentID);
  void printTable();
 private:
  int numBuckets;
  std::list<Student*> *buckets;
  int hash(int studentID);
  // std::list<Student*> buckets;

};

#endif
