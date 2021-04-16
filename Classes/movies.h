#ifndef MOVIES_H
#define MOVIES_H

#include <iostream>
#include <cstring>
#include "media.h"

using namespace std;

class Movie : public Media {
 public:
  Movie();
  virtual int getType();
  char* getDirector();
  int* getDuration();
  float* getRating();
 private:
  char director[30];
  int duration;
  float rating;
};
#endif
