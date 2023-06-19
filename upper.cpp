/*
Author: Darren Moy 
Course: CSCI-135
Instructor: Genady Maryash
Assignment: 

Prints the bottom left half of a square given the side length

Gradescope is my life
I will document every single line of my code
I will not shed tears while I write my code
I am currently working on trying to fix the problems I created when I tried to fix the problems
I created when I tried to fix the problems I created when ...
@returns the bottom left half of a square 
*/

#include <iostream>
using namespace std;

int main()
{
    int length;
    cout << "Input side length: ";
    cin >> length;

    cout << "Shape: " << endl;

    for (int i = 0; i < length; i++) // row 
    {
        for (int j = 0; j < length; j++) //col
        {
            if (i == j || i < j)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
