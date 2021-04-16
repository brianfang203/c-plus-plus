#include <iostream>
#include <vector>
#include <cstring>
#include "media.h"
#include "movies.h"
#include "games.h"
#include "music.h"

using namespace std;

//program functions
void ADD(vector<Media*>* media);
void SEARCH(char* title, vector<Media*>* media);
void DELETE(char* title, vector<Media*>* media);
void SEARCH(int year, vector<Media*>* media);
void DELETE(int year, vector<Media*>* media);

int main() {
	bool run = true;
	char input[10];
	char ttl[30];
	int yr;
	vector<Media*> mediaList;
	
	//keep running until user says to quit
	while(run) {
		
		//reading in user input
		cout << "Do you want to ADD, SEARCH, DELETE, or QUIT: " << endl;
		cin.get(input, 10);
		cin.clear();
		cin.ignore(10000, '\n');
		
		//adding media
		if(strcmp(input, "ADD") == 0) {
			ADD(&mediaList);
		}
		
		//searching media
		else if(strcmp(input, "SEARCH") == 0) {
			cout << "Do you want to search by title or year: " << endl;
			cin.get(input, 6);
			cin.clear();
			cin.ignore(10000, '\n');
			
			//search by title
			if(strcmp(input, "title") == 0) {
				cout << "Enter title: " << endl;
				cin.get(ttl, 30);
				cin.clear();
				cin.ignore(10000, '\n');
				SEARCH(ttl, &mediaList);
			}
			
			//search by year
			else if(strcmp(input, "year") == 0) {
				cout << "Enter year: " << endl;
				cin >> yr;
				cin.clear();
				cin.ignore(10000, '\n');
				SEARCH(yr, &mediaList);
			}
		}
		
		//delete media
		else if(strcmp(input, "DELETE") == 0) {
			cout << "Do you want to delete by title or year: " << endl;
			cin.get(input, 6);
			cin.clear();
			cin.ignore(10000, '\n');
			
			//delete by title
			if(strcmp(input, "title") == 0) {
				cout << "Enter title: " << endl;
				cin.get(ttl, 30);
				cin.clear();
				cin.ignore(10000, '\n');
				DELETE(ttl, &mediaList);
			}
			
			//delete by year
			else if(strcmp(input, "year") == 0) {
				cout << "Enter year: " << endl;
				cin >> yr;
				cin.clear();
				cin.ignore(10000, '\n');
				DELETE(yr, &mediaList);
			}
		}
		
		//stopping program
		else if(strcmp(input, "QUIT") == 0) {
			run = false; 
		}
		
		//incorrect format
		else {
			cout << "Incorrect format" << endl;
		}
	}
	return 0;
}

//add function
void ADD(vector<Media*>* media) {
	char input[30];
	cout << "Do you want to add a movie, videogame, or music: " << endl;
	cin.get(input, 12);
	cin.clear();
	cin.ignore(10000, '\n');
	
	//adding movie
	if(strcmp(input,"movie") == 0) {
		Movie* movie = new Movie();
		cout << "Enter title: " << endl;
		cin.get(movie->getTitle(), 30);
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Enter year: " << endl;
		cin >> *movie->getYear();
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Enter director: " << endl;
		cin.get(movie->getDirector(), 30);
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Enter duration in minutes: " << endl;
		cin >> *movie->getDuration();
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Enter rating out of 5: " << endl;
		cin >> *movie->getRating();
		cin.clear();
		cin.ignore(10000, '\n');
		media->push_back(movie);
	}
	
	//adding video game
	else if(strcmp(input, "videogame") == 0) {
		Game* videogame = new Game();
		cout << "Enter title: " << endl;
		cin.get(videogame->getTitle(), 30);
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Enter year: " << endl;
		cin >> *videogame->getYear();
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Enter publisher: " << endl;
		cin.get(videogame->getPublisher(), 30);
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Enter rating out of 5: " << endl;
		cin >> *videogame->getRating();
		cin.clear();
		cin.ignore(10000, '\n');
		media->push_back(videogame);
	}
	
	//adding music
	else if(strcmp(input, "music") == 0) {
		Music* music = new Music();
		cout << "Enter title: " << endl;
		cin.get(music->getTitle(), 30);
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Enter artist: " << endl;
		cin.get(music->getArtist(), 30);
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Enter duration in seconds: " << endl;
		cin >> *music->getDuration();
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Enter publisher: " << endl;
		cin.get(music->getPublisher(), 30);
		cin.clear();
		cin.ignore(10000, '\n');
		media->push_back(music);
	}
	
	//incorrect format
	else {
		cout << "Incorrect format" << endl;
	}
}

//search by title function
void SEARCH(char* title, vector<Media*>* media) {
	vector<Media*>::iterator iter;
	for (iter = media->begin(); iter != media->end(); ++iter) {
		if (strcmp(title, (*iter)->getTitle()) == 0) {
			cout << (*iter)->getTitle() << ", ";
			cout << *(*iter)->getYear() << endl;
			
			//search movie
			if((*iter)->getType() == 0) {
				cout << "  Directed by " << dynamic_cast<Movie*>(*iter)->getDirector() << endl;
				cout << "  Duration of " << *dynamic_cast<Movie*>(*iter)->getDuration() << " minutes" << endl;
				cout << "  Rating of " << *dynamic_cast<Movie*>(*iter)-> getRating() << " stars" << endl << endl;
			}
			
			//search music
			else if((*iter)->getType() == 1) {
				cout << "  Music by " << dynamic_cast<Music*>(*iter)->getArtist() << endl;
				cout << "  Duration of " << *dynamic_cast<Music*>(*iter)->getDuration() << " seconds" << endl;
				cout << "  Published by " << dynamic_cast<Music*>(*iter)->getPublisher() << endl << endl; 
			}
			
			//search video games
			else if((*iter)->getType() == 2) {
				cout << "  Published by " << dynamic_cast<Game*>(*iter)->getPublisher() << endl;
				cout << "  Rating of " << *dynamic_cast<Game*>(*iter)->getRating() << " stars" << endl;
			}
		}
	}
}

//search by year function
void SEARCH(int year, vector<Media*>* media) {
	vector<Media*>::iterator iter;
	for(iter = media->begin(); iter != media->end(); ++iter) {
		if(year == *(*iter)->getYear()) {
			cout << (*iter)->getTitle() << ", ";
			cout << *(*iter)->getYear() << endl;
			
			//search movie
			if((*iter)->getType() == 0) {
				cout << "  Directed by " << dynamic_cast<Movie*>(*iter)->getDirector() << endl;
				cout << "  Duration of " << *dynamic_cast<Movie*>(*iter)->getDuration() << " minutes" << endl;
				cout << "  Rating of " << *dynamic_cast<Movie*>(*iter)-> getRating() << " stars" << endl << endl;
			}
			
			//search music
			else if((*iter)->getType() == 1) {
				cout << "  Music by " << dynamic_cast<Music*>(*iter)->getArtist() << endl;
				cout << "  Duration of " << *dynamic_cast<Music*>(*iter)->getDuration() << " seconds" << endl;
				cout << "  Published by " << dynamic_cast<Music*>(*iter)->getPublisher() << endl << endl;
			}
			
			//search video game
			else if((*iter)->getType() == 2) {
				cout << "  Published by " << dynamic_cast<Game*>(*iter)->getPublisher() << endl;
				cout << "  Rating of " << *dynamic_cast<Game*>(*iter)->getRating() << " stars" << endl;
			}
		}
	}
}

//delete by title function
void DELETE(char* title, vector<Media*>* media) {
	char input[4];
	vector<Media*>::iterator iter;
	for(iter = media->begin(); iter != media->end(); ++iter) {
		if(strcmp(title, (*iter)->getTitle()) == 0) {
			cout << (*iter)->getTitle() << ", ";
			cout << *(*iter)->getYear() << endl;
			
			//deleting movie
			if((*iter)->getType() == 0) {
				cout << "  Directed by " << dynamic_cast<Movie*>(*iter)->getDirector() << endl;
				cout << "  Duration of " << *dynamic_cast<Movie*>(*iter)->getDuration() << " minutes" << endl;
				cout << "  Rating of " << *dynamic_cast<Movie*>(*iter)-> getRating() << " stars" << endl << endl;
			}
			
			//deleting music
			else if((*iter)->getType() == 1) {
				cout << "  Music by " << dynamic_cast<Music*>(*iter)->getArtist() << endl;
				cout << "  Duration of " << *dynamic_cast<Music*>(*iter)->getDuration() << " seconds" << endl;
				cout << "  Published by " << dynamic_cast<Music*>(*iter)->getPublisher() << endl << endl;
			}
			
			//deleting video games
			else if((*iter)->getType() == 2) {
				cout << "  Published by " << dynamic_cast<Game*>(*iter)->getPublisher() << endl;
				cout << "  Rating of " << *dynamic_cast<Game*>(*iter)->getRating() << " stars" << endl;
			}
			cout << "Do you want to delete this media (yes/no): " << endl;
			cin.get(input, 4);
			cin.clear();
			cin.ignore(10000, '\n');
			
			//delete from media
			if(strcmp(input, "yes") == 0) {
				delete *iter;
				iter = media->erase(iter);
				return;
			}
		}
	}
}

//delete by year function
void DELETE(int year, vector<Media*>* media) {
	char input[5];
	vector<Media*>::iterator iter;
	for (iter = media->begin(); iter != media->end(); ++iter) {
		if (year == *(*iter)->getYear()) {
			cout << (*iter)->getTitle() << ", ";
			cout << *(*iter)->getYear() << endl;
			
			//deleting movie
			if((*iter)->getType() == 0) {
				cout << "  Directed by " << dynamic_cast<Movie*>(*iter)->getDirector() << endl;
				cout << "  Duration of " << *dynamic_cast<Movie*>(*iter)->getDuration() << " minutes" << endl;
				cout << "  Rating of " << *dynamic_cast<Movie*>(*iter)-> getRating() << " stars" << endl << endl;
			}
			
			//deleting music
			else if((*iter)->getType() == 1) {
				cout << "  Music by " << dynamic_cast<Music*>(*iter)->getArtist() << endl;
				cout << "  Duration of " << *dynamic_cast<Music*>(*iter)->getDuration() << " seconds" << endl;
				cout << "  Published by " << dynamic_cast<Music*>(*iter)->getPublisher() << endl << endl;
			}
			
			//deleting video games
			else if((*iter)->getType() == 2) {
				cout << "  Published by " << dynamic_cast<Game*>(*iter)->getPublisher() << endl;
				cout << "  Rating of " << *dynamic_cast<Game*>(*iter)->getRating() << " stars" << endl;
			}
			cout << "Do you want to delete this media (yes/no): " << endl;
			cin.get(input, 4);
			cin.clear();
			cin.ignore(10000, '\n');
			
			//delete from media
			if(strcmp(input, "yes") == 0) {
				delete *iter;
				iter = media->erase(iter);
				return;
			}
		}
	}
}
