/*
Author: Darren Moy
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Project 2 C

:

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
#include <math.h>
using namespace std;

int g_capacity = 2;
int g_size = 0;

class Song
{
public:
    string name;
    string artist;
    int duration;
    string genre;
};

Song *g_songs = new Song[g_capacity];

void allocateNew()
{
    int new_capacity = g_capacity * 2;
    Song *new_songs = new Song[new_capacity];

    for (int i = 0; i < g_size; i++)
    {
        new_songs[i] = g_songs[i];
    }

    delete[] g_songs;
    g_songs = new_songs;
    g_capacity = new_capacity;
}

void readSongs(string filename)
{
    ifstream fin(filename);
    if (fin.fail())
    {
        cerr << "Error reading file." << endl;
        exit(1);
    }
    string junk, song_name, artist_name, genre, duration_prelim;
    int duration;

    while (fin)
    {
        if (g_capacity == g_size)
        {
            allocateNew();
        }
        getline(fin, song_name, ':');
        getline(fin, artist_name, '-');
        getline(fin, genre, '-');
        getline(fin, duration_prelim, ' ');
        getline(fin, junk);

        duration = stoi(duration_prelim);

        g_songs[g_size].name = song_name;
        g_songs[g_size].artist = artist_name;
        g_songs[g_size].duration = duration;
        g_songs[g_size].genre = genre;

        g_size++;
    }

    g_size--;
    fin.close();
}

Song *getSongsFromDuration(int duration, int &durationsCount, int filter)
{
    Song *durationSongs = new Song[g_size];
    durationsCount = 0;

    for (int i = 0; i < g_size; i++)
    {
        if (filter == 0)
        {
            if (g_songs[i].duration > duration)
            {
                durationSongs[durationsCount].name = g_songs[i].name;
                durationSongs[durationsCount].genre = g_songs[i].genre;
                durationSongs[durationsCount].duration = g_songs[i].duration;
                durationSongs[durationsCount].artist = g_songs[i].artist;
                durationsCount++;
            }
        }
        if (filter == 1)
        {
            if (g_songs[i].duration < duration)
            {
                durationSongs[durationsCount].name = g_songs[i].name;
                durationSongs[durationsCount].genre = g_songs[i].genre;
                durationSongs[durationsCount].duration = g_songs[i].duration;
                durationSongs[durationsCount].artist = g_songs[i].artist;
                durationsCount++;
            }
        }
        if (filter == 2)
        {
            if (g_songs[i].duration == duration)
            {
                durationSongs[durationsCount].name = g_songs[i].name;
                durationSongs[durationsCount].genre = g_songs[i].genre;
                durationSongs[durationsCount].duration = g_songs[i].duration;
                durationSongs[durationsCount].artist = g_songs[i].artist;
                durationsCount++;
            }
        }
    }

    return durationSongs;
}

Song *getGenreSongs(string genre, int &genreCount)
{
    Song *genreSongs = new Song[g_size];
    genreCount = 0;
    for (int i = 0; i < g_size; i++)
    {
        if (g_songs[i].genre == genre)
        {
            genreSongs[genreCount].genre = g_songs[i].genre;
            genreSongs[genreCount].name = g_songs[i].name;
            genreSongs[genreCount].duration = g_songs[i].duration;
            genreSongs[genreCount].artist = g_songs[i].artist;
            genreCount++;
        }
    }
    return genreSongs;
}

string *getUniqueArtists(int &uniqueCount)
{
    string *unique = new string[g_size];
    uniqueCount = 0;
    bool isUnique;

    for (int i = 0; i < g_size; i++){
        isUnique = false;

        for (int j = 0; j < uniqueCount; j++)
        {
            if (unique[j] == g_songs[i].artist){
                isUnique = true;
                break;
            }
        }
        if (!isUnique){
            unique[uniqueCount] = g_songs[i].artist;
            uniqueCount++;
        }
    }
    return unique;
}
string getFavoriteArtist(){
    if (g_size == 0) {
        return "NONE";
    }
    string favoriteArtist = "";
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
            favoriteArtist = g_songs[i].artist;
        }
    }
    
    return favoriteArtist;
}
