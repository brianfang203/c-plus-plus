#include <iostream>
#include <stdio.h>
#include <cstring>
#include <iomanip>
#include "Node.h"
#include "Student.h"

using namespace std;

//prototypes
void addNew(Node* previous, Student* student);
void print(Node* next);
float average(Node* next);
void remove(Node* next, Node* previous, char name[]);

Node* first = NULL;

//main
int main() {
	std::cout << std::fixed;
	std::cout << std::setprecision(2);
  
  	//while still running
	while (true) {
		char input[10];
		int intInput;
		float floatInput;
    
    		//user input
		cout << "Would you like to ADD, PRINT, DELETE, AVERAGE, QUIT: " << endl;
		cin.get(input, 10);
		cin.clear();
		cin.ignore(1000000, '\n');

    		//if input is add
		if (strcmp(input, "ADD") == 0) {
			Student* newStudent = new Student;
      
      			//adding first name
			cout << endl << "First name: " << endl << ">> ";
			cin.get(newStudent -> getFirst(), 10);
			cin.clear();
			cin.ignore(1000000, '\n');
      
      			//adding last name
			cout << "Last name: " << endl << ">> ";
			cin.get(newStudent -> getLast(), 10);
			cin.clear();
			cin.ignore(1000000, '\n');
      
      			//adding id
			cout << "ID: " << endl << ">> ";
			cin >> intInput;
			cin.clear();
			cin.ignore(1000000, '\n');
			newStudent -> setID(intInput);
      
      			//adding GPA
			cout << "GPA: " << endl << ">> ";
			cin >> floatInput;
			cin.clear();
			cin.ignore(1000000, '\n');
			newStudent -> setGPA(floatInput);
			addNew(first, newStudent);
			cout << "Student added!" << endl << endl;
		} 
    
		//if input is print
		else if (strcmp(input, "PRINT") == 0) {
			if (first == NULL) {
				cout << endl << "Currently no students" << endl << endl;
			}
      
      			//printing students
 			else {
				cout << endl;
				print(first);
			}
		}
    
		//if input is delete
		else if (strcmp(input, "DELETE") == 0) {
			if (first == NULL) {
				cout << endl << "There are no students to delete" << endl << endl;
			}
      
      			//deleting student
			else {
				cout << endl << "First name of the student you want to delete: " << endl << ">> ";
				cin.get(input, 10);
				cin.clear();
				cin.ignore(1000000, '\n');
				remove(first, NULL, input);
			}
		}
    
		//if input is average
		else if (strcmp(input, "AVERAGE") == 0) {
			if (first == NULL) {
				cout << endl << "Currently no students" << endl << endl;
			}
      
      			//averaging GPA
			else {
				cout << endl << "Average GPA: " << average(first) << endl << endl;
			}
		}
    
		//if input is quit
		else if (strcmp(input, "QUIT") == 0 || strcmp(input, "quit") == 0) {
			break;
		}
    
    		//incorrect format
		else {
			cout << "Incorrect format" << endl;
		}
	}
	return 0;
}

//add new student
void addNew(Node* previous, Student* student) {
	if (first == NULL) {
		first = new Node(student);
	}
	else if (student -> getID() < first -> getStudent() -> getID()) {
		Node* temp = new Node(first -> getStudent());
		temp -> setNext(first -> getNext());
		first -> setStudent(student);
		first -> setNext(temp);
	}
	else if (previous -> getNext() == NULL) {
		Node* newNode = new Node(student);
		previous -> setNext(newNode);
	}
	else if (student -> getID() < previous -> getNext() -> getStudent() -> getID()) {
		Node* newNode = new Node(student);
		newNode -> setNext(previous -> getNext());
		previous -> setNext(newNode);
	}
	else {
		addNew(previous -> getNext(), student);
	}
}

//print students
void print(Node* next) {
	if (next != NULL) {
		cout << next -> getStudent() -> getLast() << ", ";
		cout << next -> getStudent() -> getFirst() << endl;
		cout << next -> getStudent() -> getID() << endl;
		cout << next -> getStudent() -> getGPA() << endl << endl;
		print(next -> getNext());
	}
}

//remove student
void remove(Node* next, Node* previous, char name[]) {
	char yesno;
  
	//first student
	if (next == first && strcmp(next -> getStudent() -> getFirst(), name) == 0) {
		cout << endl << next -> getStudent() -> getLast() << ", ";
		cout << next -> getStudent() -> getFirst() << endl;
		cout << next -> getStudent() -> getID() << endl;
		cout << next -> getStudent() -> getGPA() << endl << endl;
		cout << "Do you want to delete this student(y/n): " << endl << ">> ";
		cin >> yesno;
		cin.clear();
		cin.ignore(1000000, '\n');
    
    		//delete student
		if (yesno == 'y') {
			cout << "Student has been deleted" << endl << endl;
			if (next -> getNext() == NULL) {
				next -> ~Node();
				first = NULL;
			}
			else {
				first = next -> getNext();
				next -> ~Node();
				remove(first, NULL, name);
			}
		}
    
    		//cancel deleting student
		else if (yesno == 'n') {
			cout << "Canceled" << endl << endl;
			if (next -> getNext() != NULL) {
				remove(next -> getNext(), next, name);
			}
		}
    
    		//incorrect format
		else {
			cout << "Incorrect format" << endl << endl;
		}
	}
  
  	//rest of students
	else if (strcmp(next -> getStudent() -> getFirst(), name) == 0) {
		cout << endl << next -> getStudent() -> getLast() << ", ";
		cout << next -> getStudent() -> getFirst() << endl;
		cout << next -> getStudent() -> getID() << endl;
		cout << next -> getStudent() -> getGPA() << endl << endl;
		cout << "Do you want to delete this student(y/n): " << endl << ">> ";
		cin >> yesno;
		cin.clear();
		cin.ignore(1000000, '\n');
    
   	 	//delete student
		if (yesno == 'y') {
			cout << "Student has been deleted" << endl << endl;
			previous -> setNext(next -> getNext());
			next -> ~Node();
		}
    
    		//cancel deleting student
		else if (yesno == 'n') {
			cout << "Canceled" << endl << endl;
		}
    
    		//incorrect format
		else {
			cout << "Incorrect format" << endl << endl;
		}
	}
	if (next -> getNext() != NULL) {
		remove(next -> getNext(), next, name);
	}
}
//average for students
float average(Node* next) {
	float total = 0;
	int counter = 0;
  
  	//if first student
	if (next == first) {
		total += next -> getStudent() -> getGPA();
		counter++;
	}
  
  	//add rest of students and average
	while (next -> getNext() != NULL) {
		total += next -> getNext() -> getStudent() -> getGPA();
		counter++;
		next = next -> getNext();
	}
	return (total/counter);
}
