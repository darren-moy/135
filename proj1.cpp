
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
#include <stdlib.h>
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
    }

    return count;
}

bool addWord(string word, string definition, string pos)
{
    int size = sizeof(g_words) / sizeof(g_words[0]);
    if (g_word_count != g_MAX_WORDS)
    {
        for (int i = 0; i < size; i++)
        {
            if (word == g_words[i])
            {
                return false;
            }

            else
            {
                g_words[g_word_count] = word;
                g_pos[g_word_count] = pos;
                g_definitions[g_word_count] = definition;
                g_word_count += 1;
                return true;
            }
        }
    }
    return 0;
}

bool editWord(string word, string definition, string pos)
{
    int size = sizeof(g_words) / sizeof(g_words[0]);
    for (int i = 0; i < size; i++)
        {
            if (word == g_words[i])
            {
                g_definitions[i] = definition;
                g_pos[i] = pos;

                return true;
        }
        }
    return false;
}

bool removeWord(string word)
{
    int index = getIndex(word);

    if (getIndex(word) > -1)
    {
        for (int i = index; i < g_word_count; i++)
        {
            g_words[i] = g_words[i+1];
            g_definitions[i] = g_definitions[i+1];
            g_pos[i] = g_pos[i+1];
        }
        g_word_count --;
        return true;
    }

    return false;

}

string getRandomWord() {
    srand((unsigned) time(NULL));
    int index = rand() % g_word_count;
    return g_words[index];
}

string maskWord(string word)
{
    string mask = "";
    for (int i = 0; i < word.length(); i++)
    {
        mask += "_";
    }
    return mask;
}

int getTries(int difficulty)
{
    if (difficulty == 0)
    {
        return 9;
    }
    if (difficulty == 1)
    {
        return 7;
    }
    if (difficulty == 2)
    {
        return 5;
    }
}

void printAttempts(int tries, int difficulty)
{
    int diff = getTries(difficulty);
    for (int i = 0; i < tries; i++)
    {
        cout << "O";
    }
    for (int j = 0; j < diff - tries; j++)
    {
        cout << "X";
    }
}

bool revealLetter(string word, char letter, string &current)
{
    bool found_letter = false;
    for (int i = 0; i < word.length(); i++)
    {
        if (word[i] == letter)
        {
            found_letter = true;
            current[i] = letter;
        }
    }
    return found_letter;
}

void gameLoop() {
    int difficulty, tries;
    string word, current;
    char letter;
    while (true) {
        cout << "Welcome to Hangman!" << endl;
        cout <<  "0. easy\n1. normal\n2. hard\n3. exit\nChoose a difficulty: ";
        cin >> difficulty;
        while (difficulty < 0 || difficulty > 3) {
            cout <<  "Enough horseplay >_< !\n0. easy\n1. normal\n2. hard\n3. exit\nChoose a difficulty: ";
            cin >> difficulty;
        }
        if (difficulty == 3) {
            cout << "If you're hangry, go grab a bite! See what I did there?" << endl;
            break;
        }
        word = getRandomWord();
        current = maskWord(word);
        tries = getTries(difficulty);
        while (tries != 0) {
            cout << "Life: ";
            printAttempts(tries, difficulty);
            cout << endl << "Word: "<< current << endl;
            cout << "Enter a letter: ";
            cin >> letter;
            
            if (!revealLetter(word, letter, current)) {
                tries--;
            }
            if (current == word) {
                break;
            }
            if (tries == 2) {
                cout << "The part of speech of the word is "<< getPOS(word) << endl;
            }
            if (tries == 1) {
                cout << "Definition of the word: " << getDefinition(word) << endl;
            }
        }
        if (tries == 0) {
            cout << "The word is \"" << word << "\". Better luck next time! You're getting the ..ahem.. hang of it." << endl;
        }
        else {
            cout << "Congrats!!!" << endl;
        }
    }
}

