#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <cstring>
#include "Student.h"

using namespace std;

class Node { 
 public:
  Node(Student*); 
  ~Node(); 
  void setStudent(Student* newstudent); 
  Student* getStudent(); 
  void setNext(Node* newnext); 
  Node* getNext(); 
 private:
  Student* student; 
  Node* next; 
};
#endif
