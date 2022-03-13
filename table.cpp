//libraries
#include <iostream>
#include "table.h"

using namespace std;

Table::Table(int numBuckets){//constructor class
  this->numBuckets = numBuckets;
  buckets = new Node[numBuckets];
}

Table::~Table(){//destructor
  cout << "deletes something" << endl;
  //itterate over buckets in table, for each bucket delete each list inside it and each student object
  for (int i = 0; i < numBuckets; i++) {
    
  }
  delete buckets;
}

void Table::printTable(){
  cout << "prints whole table" << endl;
  //itterate over buckets in table, for each bucket print each list inside it and each student object
}

void Table::add(Student* student){
  int bucketID = hash(student->getStudentID());
  addToBUcket(&buckets[bucketID], NULL, buckets[bucketID], student);
  cout << "adds a student" << endl;
}

void Table::addToBucket(Node** head, Node* previous, Node* current, Student* student) {
  Node* newNode = NULL;
  if (current == NULL) {
    newNode = new Node(student);
    if (previous != NULL) {
      previous->setNext(newNode);
    }
    else {
      *head = newNode;
    }
  }
  else {
    if (current != NULL && student->getStudentID() > current->getStudent()->getStudentID()) {
      addToBucket(head, current, current->getNext(), student);
      return;
    }
    newNode = new Node(student);
    if (previous == NULL) {
      *head = newNode;
    }
    else {
      previous->setNext(newNode);
    }

    newNode->setNext(current);
  }
}

void Table::rmStudent(int studentID){
  cout << "removes a student" << endl;

}

int Table::hash(int studentID){
  cout << "hashes a thing" << endl;
  return (studentID % this->numBuckets);
}
