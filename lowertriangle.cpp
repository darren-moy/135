
/*
Author: Darren Moy 
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Lab 4 Task D

Prints lower half of a square given a side length 

Gradescope is my life
I will document every single line of my code
I will not shed tears while I write my code
I am currently working on trying to fix the problems I created when I tried to fix the problems
I created when I tried to fix the problems I created when ...
@returns lower half of a square 
*/

#include <iostream>
using namespace std;

int main()
{
    int length;
    cout << "Input side length: ";
    cin >> length;

    cout << "Shape: " << endl;
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length; j++)
        {
            if (i == j || i > j)
            {
                cout << "*";
            }
        }
        cout << endl;
    }

    return 0;
}