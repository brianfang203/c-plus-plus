#include <iostream>
#include <cstring>
#include "media.h"
#include "music.h"

using namespace std;

Music::Music()
{

}

char* Music::getArtist(){
  return artist;
}

char* Music::getPublisher(){
  return publisher;
}

int* Music::getDuration(){
  return &duration;
}

int Music::getType(){
  return 1;
}
