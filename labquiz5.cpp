/*
Author: Darren Moy 
Course: CSCI-135
Instructor: Genady Maryash
Assignment:Lab quiz 5 

prints out a square full of plus signs 

Gradescope is my life
I will document every single line of my code
I will not shed tears while I write my code
I am currently working on trying to fix the problems I created when I tried to fix the problems
I created when I tried to fix the problems I created when ...
@returns a square 
*/

#include <iostream>
using namespace std;

int main()
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << "+";
        }
        cout << endl;
    }
    return 0;
}
