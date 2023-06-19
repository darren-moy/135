/*
Author: Darren Moy 
Course: CSCI-135
Instructor: Genady Maryash
Assignment: 

:

Gradescope is my life
I will document every single line of my code
I will not shed tears while I write my code
I am currently working on trying to fix the problems I created when I tried to fix the problems
I created when I tried to fix the problems I created when ...
@returns :
*/

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <climits>
#include <stdlib.h>
using namespace std;

void remove_e(string & sentence)
{
    string ans;
    for (int i = 0; i < sentence.length(); i++)
    {
        if (sentence[i] != 'e')
        {
            ans = ans + sentence[i];
        }
    }
    sentence = ans;
}

int main()
{
    string s = "Elephant";
    remove_e(s);
    cout << s << endl;
    return 0;
}
