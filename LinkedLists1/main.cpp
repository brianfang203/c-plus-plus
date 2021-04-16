#include <iostream>
#include <cstring>
#include <stdio.h>
#include <iomanip>
#include "node.h"
#include "student.h"

using namespace std;

int main() {
  
	char input[20];
  
  	//create student
	Student* stud = new Student;
	cout << "Enter student's first name: " << endl;
	cin.get(stud -> getFirst(), 50);
	cin.clear();
	cin.ignore(10000, '\n');
	cout << "Enter student's last name: " << endl;
	cin.get(stud -> getLast(), 50);
	cin.clear();
	cin.ignore(10000, '\n');
	cout << "Enter student's ID: " << endl;
	cin >> *stud -> getId();
	cin.clear();
	cin.ignore(10000, '\n');
	cout << "Enter student's GPA: " << endl;
	cin >> *stud -> getGpa();
	cin.clear();
	cin.ignore(10000, '\n');

	//print student info
	cout << "Student name: " << stud -> getFirst() << " " << stud -> getLast() << ", ";
	cout << "ID: " << *stud -> getId() << ", ";
	cout << "GPA: " << fixed << setprecision(2) << *stud -> getGpa() << endl;

	//setup and print nodes
	Node* studentNode = new Node(stud);
	studentNode -> setStudent(stud);
	cout << "Nodes: " << endl;
	cout << studentNode -> getStudent() -> getFirst() << " " << studentNode -> getStudent() -> getLast() << endl;

	return 0;
}
