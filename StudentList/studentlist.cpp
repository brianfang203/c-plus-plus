#include <iostream>
#include <cstring>
#include <vector>
#include <iomanip>
using namespace std;

//student struct
struct Student {
	char first[50];
	char last[50];
	int id;
	float gpa;
};

//adding student
void add(vector<Student*> &list) {
	list.push_back(new Student());
	cout << "First Name: " << endl;
	cin >> list.back()->first;
	cout << "Last Name: " << endl;
	cin >> list.back()->last;
	cout << "ID Number: " << endl;
	cin >> list.back()->id;
	cout << "GPA: " << endl;
	cin >> list.back()->gpa;
}

//printing students
void print(vector<Student*> list) {

	//iterate through vector
	for(vector<Student*>::iterator i = list.begin(); i != list.end(); i++) {
		cout << list[i - list.begin()]->first << " " << list[i - list.begin()]-> last << ", " << list[i - list.begin()]->id << ", " << setprecision(2) << fixed << list[i - list.begin()]->gpa << endl;
	}
}

//deleting student
void del(vector<Student*> &list) {
	cout << "Enter ID number of student to be deleted: " << endl;
	int deleteId;
	cin >> deleteId;

	//iterate through vector
	for(vector<Student*>::iterator i = list.begin(); i != list.end(); i++) {

		//if it matches then delete
		if(list[i - list.begin()]->id == deleteId) {
			delete list[i - list.begin()];
			list.erase(list.begin()+(i - list.begin()));
		}
	}
}

//main function
int main() {
	bool run = true;
	vector <Student*>* list = new vector<Student*>();
	char cmd[10];

	//while keep running
	while (run == true) {

		//asking for user input
		cout << "\nWould you like to ADD, DELETE, PRINT, or QUIT" << endl;
		cin >> cmd;

		//adding student
		if (strcmp(cmd,"ADD") == 0) {
			add(*list);
			cout << "Student added" << endl;
		}

		//deleting student
		else if (strcmp(cmd,"DELETE") == 0) {
			del(*list);
			cout << "Student deleted";
		}

		//printing students
		else if (strcmp(cmd,"PRINT") == 0) {
			print(*list);
			cout << "Students printed";
		}

		//quitting program
		else if (strcmp(cmd,"QUIT") == 0) {
			run = false;
		}

		//incorrect formatting or can't read
		else {
			cout << "Incorrect format";
		}
	}
}
