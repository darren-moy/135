
/*
Author: Darren Moy 
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Project 1 Task A 

A dictionary using arrays 

Gradescope is my life
I will document every single line of my code
I will not shed tears while I write my code
I am currently working on trying to fix the problems I created when I tried to fix the problems
I created when I tried to fix the problems I created when ...
@returns the number of words read 
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
using namespace std;

const int g_MAX_WORDS = 1000;
int g_word_count = 0;

string g_words[g_MAX_WORDS];
string g_definitions[g_MAX_WORDS];
string g_pos[g_MAX_WORDS];

void readWords(string file_name)
{
    ifstream fin (file_name);
    if (fin.fail())
    {
        cerr << "File cannot be opened for reading." << endl;
        exit(1);
    }

    string line;
    string word, pos, col, def;
    while (fin >> word >> pos >> col)
    {
        g_words[g_word_count] = word;
        g_pos[g_word_count] = pos;

        getline(fin, def);
        g_definitions[g_word_count] = def.substr(1);
        g_word_count += 1;

    }
    for (int i= 0; i < g_word_count ; i++)
        {
            cout << g_words[i] << " " << g_pos[i] << col << " " << g_definitions[i] << endl;
        }
}

int getIndex(string word)
{
    int size = sizeof(g_words) / sizeof(g_words[0]);
    for (int i = 0; i < size; i++)
    {
        if (word == g_words[i])
        {
            return i;
        }
    }

    return -1;
}

string getDefinition(string word)
{
    int size = sizeof(g_words) / sizeof(g_words[0]);
    for (int i = 0; i < size; i++)
    {
        if (word == g_words[i])
        {
            return g_definitions[i];
        }
    }

    return "NOT_FOUND";
}

string getPOS(string word)
{
    int size = sizeof(g_words) / sizeof(g_words[0]);
    for (int i = 0; i < size; i++)
    {
        if (word == g_words[i])
        {
            return g_pos[i];
        }
    }

    return "NOT_FOUND";
}

int countPrefix(string prefix)
{
    int count = 0;
    int size = sizeof(g_words) / sizeof(g_words[0]);
    for (int i = 0; i < size; i++)
    {
        string word;
        if (g_words[i].substr(0, prefix.length()) == prefix)
        {
            count += 1;
        }
        else
        {
            count = count;
        }
    }

    return count;
}
