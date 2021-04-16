#include <iostream>
#include <cstring>
#include "student.h"

using namespace std;

Student::Student() {

}

Student::~Student() {
  delete &firstN;
  delete &lastN;
  delete &id;
  delete &gpa;
}

char* Student::getFirst() {
  return firstN;
}

char* Student::getLast() {
  return lastN;
}

int* Student::getId() {
  return &id;
}

float* Student::getGpa() {
  return &gpa;
}
