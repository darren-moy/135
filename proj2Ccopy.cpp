
/*
Author: Kevin Perez
Course: CSCI-135
Instructor: Gennadiy Maryash
Assignment: Project 2 Task C

*/
#include <fstream>
#include <cstdlib>
#include <climits>
#include <iostream>
using namespace std;

class Song{
    public:
    string name, artist, genre;
    int duration;
};

int g_capacity = 2;
int g_size = 0;
Song *g_songs = new Song[g_capacity];



Song * getGenreSongs(string genre, int &genreCount){
  Song *genreS = new Song[g_size];
  genreCount = 0;
  for (int i = 0; i < g_size; i++) {
    if (g_songs[i].genre == genre) {
      genreS[genreCount].genre = g_songs[i].genre;
      genreS[genreCount].name = g_songs[i].name;
      genreS[genreCount].duration = g_songs[i].duration;
      genreS[genreCount].artist = g_songs[i].artist;
      genreCount++;
    }
  }
  return genreS;
}


Song * getSongsFromDuration(int duration, int &durationsCount, int filter){

    Song* songZ = new Song[g_size];
    durationsCount = 0;

    for (int i = 0; i < g_size; i++) {
        if (filter == 0) {
            if (g_songs[i].duration > duration) {
                songZ[durationsCount].name = g_songs[i].name;
                songZ[durationsCount].genre = g_songs[i].genre;
                songZ[durationsCount].duration = g_songs[i].duration;
                songZ[durationsCount].artist = g_songs[i].artist;
                durationsCount++;
            }
        }
        if (filter == 1) {
            if (g_songs[i].duration < duration) {
                songZ[durationsCount].name = g_songs[i].name;
                songZ[durationsCount].genre = g_songs[i].genre;
                songZ[durationsCount].duration = g_songs[i].duration;
                songZ[durationsCount].artist = g_songs[i].artist;
                durationsCount++;
            }
        }
        if (filter == 2) {
            if (g_songs[i].duration == duration) {
                songZ[durationsCount].name = g_songs[i].name;
                songZ[durationsCount].genre = g_songs[i].genre;
                songZ[durationsCount].duration = g_songs[i].duration;
                songZ[durationsCount].artist = g_songs[i].artist;
                durationsCount++;
            }
        }
        
    }

    return songZ;

}
string *getUniqueArtists(int &uniqueCount) {
  string *unique  = new string[g_size]; 
  uniqueCount = 0;
  bool perm;

  for (int i = 0; i < g_size; i++) {
    perm = false;

    for (int j = 0; j < uniqueCount; j++) {
      if (unique[j] == g_songs[i].artist) {
        perm = true;
        break;
      }
    }
    if (!perm) {
      unique[uniqueCount] = g_songs[i].artist;
      uniqueCount++;
    }
  }
  return unique ;
}
string getFavoriteArtist() {
    string fav = "";
    int high = 0;

    for (int i = 0; i < g_size; i++) {
        int num = 0;
        for (int j = 0; j < g_size; j++) {
            if (g_songs[i].artist == g_songs[j].artist) {
                num++;
            }
        }
        if (num > high) {
            high = num;
            fav = g_songs[i].artist;
        }
    }
    if (g_size == 0) {
        return "NONE";
    }
    return fav;
}

void allocateNew(){
    int twice_size = g_capacity*2;

    Song *copied = new Song[twice_size];

    for (int i = 0; i < g_capacity; i++){
        copied[i].name = g_songs[i].name;
        copied[i].artist = g_songs[i].artist;
        copied[i].duration = g_songs[i].duration;
        copied[i].genre =  g_songs[i].genre;
    }
    delete [] g_songs;
    g_songs = copied;
    g_capacity = twice_size;
}
void readSongs(string filename){
    ifstream fin(filename);
    if (fin.fail()){
        cerr << "File could not be open";
        exit(1);
    }
    string line;
    while (getline(fin,line)){
        g_songs[g_size].name  = line.substr(0,line.find(":"));
        g_songs[g_size].artist = line.substr(line.find(":")+1,line.find("-")-line.find(":")-1);
        line = line.substr(line.find("-")+1);
        g_songs[g_size].genre = line.substr(0,line.find("-"));
        line = line.substr(line.find("-")+1);
        g_songs[g_size].duration = stoi(line.substr(0,line.find(" ")));

        g_size++;
        if (g_size == g_capacity){
            allocateNew();
        }
    }
    fin.close();
}

int main(){
    readSongs("test.txt");
    int count = 0;
    // Son = getGenreSongs("Pop",count);
    for (int i = 0; i < g_size; i++){
        cout << g_songs[i].duration << endl;
    }

    return 0;
}