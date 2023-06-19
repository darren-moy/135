/*
Author: Darren Moy 
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Project 1B Task A 

Reads a word and prints it out lette by letter on a new line 

Gradescope is my life
I will document every single line of my code
I will not shed tears while I write my code
I am currently working on trying to fix the problems I created when I tried to fix the problems
I created when I tried to fix the problems I created when ...
@returns the word inputted word by word on a new line 
*/

#include <iostream> 
using namespace std;

int main()
{
    string word;
    cin >> word;

    for (int i =0; i < word.length(); i++)
    {
        cout << word[i] << endl;
    }

    return 0;
}