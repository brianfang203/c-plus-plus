#include <iostream>
#include <cstring>
#include "media.h"
#include "games.h"

using namespace std;

Game::Game(char* newTitle, int newYear, char* newPublisher, int newRating){
     title = newTitle;
     year = newYear;
      publisher = newPublisher
     rating = newRating;
}

char* Game::getPublisher(){
  return publisher;
}

float* Game::getRating(){
  return &rating;
}

int Game::getType(){
  return 2;
}
