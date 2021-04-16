#include <iostream>
#include <cstring>
#include <vector>
#include <iomanip>
#include <map>
#include <algorithm>

#include "room.h"
#include "item.h"

using namespace std;

//initializing
void initializeRooms(vector<Room*>* rooms);
void initializeItems(vector<Item*>* items);
void printRoom(vector<Room*>* rooms, vector<Item*>* items, int currentRoom);
void printInventory(vector<Item*>* items, vector<int> invtry);
void getItem(vector<Room*>* rooms, vector<Item*>* items,vector<int>* invtry, int currentRoom, char name[]);
void dropItem(vector<Room*>* rooms, vector<Item*>* items, vector<int>* invtry, int currentRoom, char name[]);
int move(vector<Room*>* rooms, int currentRoom, char direction[]);

//main
int main() {

	bool run = true;
	vector<Room*> roomList;
	vector<Item*> itemList;
	vector<int> inventory;
	char input[30];
	int currentRoom = 1;
	initializeRooms(&roomList);
	initializeItems(&itemList);
	cout << "You are stuck at Sunset High School and need to find an escape by picking up items and finding the exit" << endl;
	cout << "Usable commands: go, get, drop, inventory, quit." << endl;

	//while user is still playing
	while (run)
	{

		//current room
		cout << endl << "You are currently in ";
		printRoom(&roomList, &itemList, currentRoom);
		cin >> input;
		cin.clear();
		cin.ignore(10000, '\n');

		//quitting program
		if (strcmp(input, "quit") == 0) {
			run = false;
		}

		//if user input is go
		else if (strcmp(input, "go") == 0) {
			cout << "Which direction would you like to go: " << endl;
			cin >> input;
			cin.clear();
			cin.ignore(10000, '\n');
			if (move(&roomList, currentRoom, input) == 0) {
				cout << endl << "Can't go any further" << endl;
			} else {
				currentRoom = move(&roomList, currentRoom, input);
			}
		}

		//check user inventory
		else if (strcmp(input, "inventory") == 0) {
			if (inventory.size() != 0) {
				cout << endl << "You have: ";
				printInventory(&itemList, inventory);
			} else {
				cout << endl << "You have nothing" << endl;
			}
		}

		//get item
		else if (strcmp(input, "get") == 0) {
			cout << "What item would you like to get: " << endl;
			cin >> input;
			cin.clear();
			cin.ignore(10000, '\n');
			getItem(&roomList, &itemList, &inventory, currentRoom, input);
		}

		//drop item
		else if (strcmp(input, "drop") == 0) {
			cout << "What item would you like to drop: " << endl;
			cin >> input;
			cin.clear();
			cin.ignore(10000, '\n');
			dropItem(&roomList, &itemList, &inventory, currentRoom, input);
		}

		//incorrect format
		else {
			cout << endl <<"Incorrect format" << endl;
		}

		//checking for a win
		for (int a = 0; a < inventory.size(); a++)
		{
			for (int b = 0; b < inventory.size(); b++)
			{
				for (int c = 0; c < inventory.size(); c++)
				{
					if (currentRoom == 1 && inventory[a] == 1 && inventory[b] == 2 && inventory[c] == 3)
					{
						cout << endl << "You have successfuly escaped Sunset High School!" << endl << endl;
						return 0;
					}
				}
			}
		}

		//checking for a loss
		for (int a = 0; a < inventory.size(); a++)
		{
			if (inventory[a] == 4 || inventory[a] == 5)
			{
				cout << endl << "I don't think you need that item..." << endl;
				cout << "You lose!" << endl << endl;
				return 0;
			}
		}
	}

	return 0;
}

//moving function
int move(vector<Room*>* rooms, int currentRoom, char direction[])
{
	vector<Room*>::iterator i;
	for(i = rooms->begin(); i != rooms->end(); i++)
	{
		if (currentRoom == (*i)->getId())
		{
			map<int, char*> exits;
			exits = *(*i) -> getExits();
			map<int, char*>::const_iterator m;
			for (m = exits.begin(); m != exits.end(); ++m)
			{
				if (strcmp(m -> second, direction) == 0)
				{
					return m -> first;
				}
			}
		}
	}
	return 0;
}

//initializing all the rooms
void initializeRooms(vector<Room*>* rooms)
{
	char* north = (char*)("north");
	char* south = (char*)("south");
	char* east = (char*)("east");
	char* west = (char*)("west");
	map<int, char*> temp;

	Room* hallA  = new Room();
	hallA -> setDescription((char*)("in the entrance hallway."));
	hallA -> setId(1);
	temp.insert(pair<int, char*> (2, east));
	temp.insert(pair<int, char*> (3, north));
	temp.insert(pair<int, char*> (4, south));
	hallA -> setExits(temp);
	hallA -> setItem(0);
	rooms -> push_back(hallA);
	temp.clear();

	Room* hallB = new Room();
	hallB -> setDescription((char*)("in the coat room."));
	hallB -> setId(4);
	temp.insert(pair<int, char*> (1, north));
	hallB -> setExits(temp);
	hallB -> setItem(0);
	rooms -> push_back(hallB);
	temp.clear();

	Room* hallC = new Room();
	hallC -> setDescription((char*)("in the dining room."));
	hallC -> setId(3);
	temp.insert(pair<int, char*> (1, south));
	temp.insert(pair<int, char*> (13, north));
	hallC -> setExits(temp);
	hallC -> setItem(0);
	rooms -> push_back(hallC);
	temp.clear();

	Room* hallD = new Room();
	hallD -> setDescription((char*)("in the garage."));
	hallD -> setId(13);
	temp.insert(pair<int, char*> (3, south));
	hallD -> setExits(temp);
	hallD -> setItem(3/*shield*/);
	rooms -> push_back(hallD);
	temp.clear();

	Room* hallE = new Room();
	hallE -> setDescription((char*)("in the living room, fun fact: you can't die in this room"));
	hallE -> setId(2);
	temp.insert(pair<int, char*> (1, west));
	temp.insert(pair<int, char*> (5, north));
	temp.insert(pair<int, char*> (8, south));
	temp.insert(pair<int, char*> (6, east));
	hallE -> setExits(temp);
	hallE -> setItem(4/*boots*/);
	rooms -> push_back(hallE);
	temp.clear();

	Room* hallF = new Room();
	hallF -> setDescription((char*)("in the bathroom."));
	hallF -> setId(5);
	temp.insert(pair<int, char*> (2, south));
	hallF -> setExits(temp);
	hallF -> setItem(5/*tp*/);
	rooms -> push_back(hallF);
	temp.clear();

	Room* hallG = new Room();
	hallG -> setDescription((char*)("in the guest bedroom."));
	hallG -> setId(6);
	temp.insert(pair<int, char*> (2, west));
	temp.insert(pair<int, char*> (7, north));
	hallG -> setExits(temp);
	hallG -> setItem(0);
	rooms -> push_back(hallG);
	temp.clear();

	Room* hallH = new Room();
	hallH -> setDescription((char*)("in the closet. Dead end!"));
	hallH -> setId(7);
	temp.insert(pair<int, char*> (6, south));
	hallH -> setExits(temp);
	hallH -> setItem(0);
	rooms -> push_back(hallH);
	temp.clear();

	Room* hallone = new Room();
	hallone -> setDescription((char*)("in the inner hallway."));
	hallone -> setId(8);
	temp.insert(pair<int, char*> (2, north));
	temp.insert(pair<int, char*> (9, west));
	temp.insert(pair<int, char*> (10, east));
	temp.insert(pair<int, char*> (11, south));
	hallone -> setExits(temp);
	rooms -> push_back(hallone);
	temp.clear();

	Room* halltwo = new Room();
	halltwo -> setDescription((char*)("in your office. No time to work."));
	halltwo -> setId(9);
	temp.insert(pair<int, char*> (8, east));
	halltwo -> setExits(temp);
	halltwo -> setItem(1/*laptop*/);
	rooms -> push_back(halltwo);
	temp.clear();

	Room* hallthree = new Room();
	hallthree -> setDescription((char*)("in the master bedroom."));
	hallthree -> setId(10);
	temp.insert(pair<int, char*> (8, west));
	temp.insert(pair<int, char*> (14, north));
	temp.insert(pair<int, char*> (12, east));
	hallthree -> setExits(temp);
	hallthree -> setItem(2/*briefcase*/);
	rooms -> push_back(hallthree);
	temp.clear();

	Room* cafeteria = new Room();
	cafeteria -> setDescription((char*)("in a secret room. You shouldn't be here!"));
	cafeteria -> setId(14);
	temp.insert(pair<int, char*> (10, south));
	cafeteria -> setExits(temp);
	cafeteria -> setItem(0);
	rooms -> push_back(cafeteria);
	temp.clear();

	Room* gym = new Room();
	gym -> setDescription((char*)("on the balcony. You can see the spaceship!"));
	gym -> setId(12);
	temp.insert(pair<int, char*> (10, west));
	gym -> setExits(temp);
	gym -> setItem(0);
	rooms -> push_back(gym);
	temp.clear();

	Room* auditorium = new Room();
	auditorium -> setDescription((char*)("in the outside garden. No exit, but there is a lovely garden"));
	auditorium -> setId(11);
	temp.insert(pair<int, char*> (8, north));
	temp.insert(pair<int, char*> (15, east));
	auditorium -> setExits(temp);
	auditorium -> setItem(0);
	rooms -> push_back(auditorium);
	temp.clear();

	Room* office = new Room();
	office -> setDescription((char*)("in the outside shed."));
	office -> setId(15);
	temp.insert(pair<int, char*> (11, west));
	office -> setExits(temp);
	office -> setItem(0);
	rooms -> push_back(office);
	temp.clear();
}

void initializeItems(vector<Item*>* items) {
	Item* boots = new Item();
	boots -> setName((char*)("remote"));
	boots -> setId(4);
	items -> push_back(boots);

	Item* tp = new Item();
	tp -> setName((char*)("toothbrush"));
	tp -> setId(5);
	items -> push_back(tp);

	Item* laptop = new Item();
	laptop -> setName((char*)("laptop"));
	laptop -> setId(1);
	items -> push_back(laptop);

	Item* bcase = new Item();
	bcase -> setName((char*)("briefcase"));
	bcase -> setId(2);
	items -> push_back(bcase);

	Item* ck = new Item();
	ck -> setName((char*)("shield"));
	ck -> setId(3);
	items -> push_back(ck);
}

//print room function
void printRoom(vector<Room*>* rooms, vector<Item*>* items, int currentRoom)
{
	vector<Room*>::iterator r;
	vector<Item*>::iterator i;
	for (r = rooms->begin(); r != rooms->end(); r++) {
		if (currentRoom == (*r)->getId()) {
			cout << (*r)->getDescription() << endl;
			cout << "  Exits: ";
			for (map<int, char*>::const_iterator it = (*r) -> getExits() -> begin(); it != (*r) -> getExits() -> end(); it++) {
				cout << it -> second << " ";
			}
			cout << endl;
			cout << "  Items in this room: ";
			int itemCount = 0; 
			for (i = items->begin(); i != items->end(); i++) {
				if ((*r)->getItem() == (*i)->getId()) {
					cout << (*i)->getName();
					itemCount++;
				}
			}
			if (itemCount == 0) {
				cout << "no items in here." << endl;
			} else {
				cout << endl;
			}
		}
	}
}

//print inventory function
void printInventory(vector<Item*>* items, vector<int> invtry) {
	vector<Item*>::iterator i;
	for (i = items->begin(); i != items->end(); i++) {
		for (int a = 0; a < invtry.size(); a++) {
			if (invtry[a] == (*i) -> getId()) {
				cout << (*i) -> getName() << " ";
			}
		}
	}
	cout << endl;
}

//get item function
void getItem(vector<Room*>* rooms, vector<Item*>* items,vector<int>* invtry, int currentRoom, char name[]) {
	vector<Room*>::iterator r;
	vector<Item*>::iterator i;
	for (r = rooms->begin(); r != rooms->end(); r++) {
		if (currentRoom == (*r) -> getId()) {
			for (i = items->begin(); i != items->end(); i++) {
				if (((*r) -> getItem() == (*i) -> getId()) && (strcmp((*i) -> getName(), name) == 0)) {
					invtry -> push_back((*i) -> getId());
					(*r) -> setItem(0);
					cout << endl << "Picked up " << (*i) -> getName() << "." << endl;
					return;
				}
			}
		} 
	}
	cout << "There is no such item in here." << endl;
}

//drop item function
void dropItem(vector<Room*>* rooms, vector<Item*>* items, vector<int>* invtry, int currentRoom, char name[]) {
	int counter;
	vector<Room*>::iterator r;
	vector<Item*>::iterator i;
	vector<int>::iterator iv;
	for(r = rooms->begin(); r != rooms->end(); r++) { 
		if(currentRoom == (*r) -> getId()) {
			if ((*r) -> getItem() == 0) {
				for (i = items->begin(); i != items->end(); i++) { 
					if (strcmp((*i) -> getName(), name) == 0) { 
						for (iv = invtry -> begin(); iv != invtry -> end(); iv++) { 
							if ((*iv) == (*i) -> getId()) {
								cout << endl << "Dropped " << (*i) -> getName() << "." << endl;
								(*r) -> setItem((*i) -> getId());
								iv = invtry -> erase(iv);
								return;
							}
						}
					}
					else if (counter == items -> size() - 1) {
						cout << endl << "No such item in your inventory." << endl;
					}
					counter++;
				}
			}
			else {
				cout << endl << "There is an item in the room already!" << endl;
			}
		}
	}
}
