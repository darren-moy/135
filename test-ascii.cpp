/*
Author: Darren Moy 
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Lab 6 Task A 

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
using namespace std;


int main()
{
    string inp;
    cout << "Input: ";
    getline(cin, inp);

    for (int i = 0; i < inp.length(); i++)
    {
        cout << inp[i] << " " << int(inp[i]) << endl;
    }

    return 0;
}
