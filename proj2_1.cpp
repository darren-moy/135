/*
Author: Darren Moy
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Project 2 

Gradescope is my life
I will document every single line of my code
I will not shed tears while I write my code
I am currently working on trying to fix the problems I created when I tried to fix the problems
I created when I tried to fix the problems I created when ...
@returns :
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cctype>
#include <climits>
#include <stdlib.h>
using namespace std;

int g_curr_size = 2;
int g_number_of_songs = 0;
int g_max_number_of_songs = g_curr_size;

string *g_song_names = new string[g_curr_size];
string *g_artist_names = new string[g_curr_size];
int *g_song_durations = new int[g_curr_size];
string *g_genres = new string[g_curr_size];

void allocateNew(){
    int new_size = g_curr_size * 2;
    int* new_song_durations = new int[new_size];
    string* new_song_names = new string[new_size];
    string* new_genres = new string[new_size];
    string* new_artist_names = new string[new_size];

    for (int i = 0; i < g_curr_size; i++){
        new_song_names[i] = g_song_names[i] ;
        new_artist_names[i] = g_artist_names[i];
        new_song_durations[i] = g_song_durations[i];
        new_genres[i] = g_genres[i];
    }   

    delete [] g_song_names;
    delete [] g_artist_names;
    delete [] g_genres;
    delete [] g_song_durations;

    g_song_names = new_song_names;
    g_artist_names = new_artist_names;
    g_song_durations = new_song_durations;
    g_genres = new_genres;
    g_curr_size = new_size;

    // Update the maximum number of songs that can be stored in the arrays
    g_max_number_of_songs = g_curr_size;
}

void readSongs(string filename){
    ifstream fin(filename);
    if(fin.fail()){
        cerr << "Cannot read from input.dat" << endl;
        exit(1);
    }
    string junk, song_name, artist_name, genre, duration_prelim;
    int duration;

    while (fin) {

        if(g_number_of_songs == g_curr_size)
        {
            allocateNew();
        }
        getline(fin, song_name, ':');
        getline(fin, artist_name, '-');
        getline(fin, genre, '-');
        getline(fin, duration_prelim, ' ');
        getline(fin, junk);

        duration = stoi(duration_prelim);

        g_song_names[g_number_of_songs] = song_name;
        g_artist_names[g_number_of_songs] = artist_name;
        g_song_durations[g_number_of_songs] = duration;
        g_genres[g_number_of_songs] = genre;

        g_number_of_songs++;
    }

    g_number_of_songs --;
    fin.close();
}


string * getGenreSongs(string genre, int &genreCount) {
    string* genreSongs = new string[g_number_of_songs];
    int index = 0;
    for(int i=0; i<g_number_of_songs; i++) {
        if(g_genres[i] == genre) {
            genreSongs[index] = g_song_names[i];
            index++;
        }
    }
    genreCount = index;
    return genreSongs;
}
   

string * getSongsFromDuration(int duration, int &durationsCount, int filter) {
    string* durationSongs = new string[g_curr_size];
    int index = 0;
    if(filter == 0) {
        for(int i=0; i<g_number_of_songs; i++) {
            if(g_song_durations[i] > duration) {
                durationSongs[index] = g_song_names[i];
                index++;
            }
        }
    }
    else if(filter == 1) {
        for(int i=0; i<g_number_of_songs; i++) {
            if(g_song_durations[i] < duration) {
                durationSongs[index] = g_song_names[i];
                index++;
            }
        }
    }
    else if(filter == 2) {
        for(int i=0; i<g_number_of_songs; i++) {
            if(g_song_durations[i] == duration) {
                durationSongs[index] = g_song_names[i];
                index++;
            }
        }
    }
    durationsCount = index;
    return durationSongs;
}

string* getUniqueArtists(int& uniqueCount) {
    string* uniqueArtistsArr = new string[g_number_of_songs];
    uniqueCount = 0;
    for (int i = 0; i < g_number_of_songs; i++) {
        bool isUnique = true;
        for (int j = 0; j < i; j++) {
            if (i != j && g_artist_names[i] == g_artist_names[j]) {
                isUnique = false;
                break;
            }
        }
        if (isUnique) {
            uniqueArtistsArr[uniqueCount] = g_artist_names[i];
            uniqueCount++;
        }
    }
    return uniqueArtistsArr;
}

string getFavoriteArtist() {
    if (g_number_of_songs == 0) {
        return "NONE";
    }
    string favoriteArtist;
    int maxSongs = 0;
    int count;
    string* uniqueArtists = getUniqueArtists(count); // get array of unique artists
    for (int i = 0; i < count; i++) {
        int artistSongCount = 0;
        for (int j = 0; j < g_number_of_songs; j++) {
            if (g_artist_names[j] == uniqueArtists[i]) {
                artistSongCount++;
            }
        }
        if (artistSongCount > maxSongs) {
            maxSongs = artistSongCount;
            favoriteArtist = uniqueArtists[i];
        }
    }
    if (maxSongs == 0) { // no songs by any unique artist
        return "NONE";
    }
    return favoriteArtist;
}
