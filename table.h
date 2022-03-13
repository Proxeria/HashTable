//header guards
#ifndef TABLE_H
#define TABLE_H

//all the libararies
#include <iostream>
#include <cstring>
#include "Student.h"
#include "node.h"

using namespace std;

class Table{
 public:
  Table(int numBuckets);
  ~Table();
  void add(Student* student);
  void rmStudent(int studentID);
  void printTable();
 private:
  Node* buckets;
  int numBuckets;
  int hash(int studentID);
  void addToBucket(Node** head, Node* previous, Node* current, Student* student);
};

#endif
