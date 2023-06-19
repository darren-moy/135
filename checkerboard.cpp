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
    int width;
    cin >> width; 

    int height;
    cin >> height;
    cout << endl;

    cout << "Shape: " << endl;

    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            if (row % 2 == col % 2)
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