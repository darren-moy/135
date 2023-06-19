/*
Author: Darren Moy 
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Lab 4 Task B 

Takes in height and width and returns a rectangular checkerboard with alternating spaces and asterisks 

Gradescope is my life
I will document every single line of my code
I will not shed tears while I write my code
I am currently working on trying to fix the problems I created when I tried to fix the problems
I created when I tried to fix the problems I created when ...
@returns a rectangular checkerboard 
*/

#include <iostream>
using namespace std;

int main()
{
    int size;
    cout << "Input size: ";
    cin >> size;

    cout << "Shape: " << endl;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if(j == size-i-1||i==j)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
        }
    cout << "\n";
    }

    return 0;
}