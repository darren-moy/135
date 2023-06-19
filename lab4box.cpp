/*
Author: Darren Moy 
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Lab 4 task A 

Takes width and height input from user and prints out a box of requested size using asteriks 

Gradescope is my life
I will document every single line of my code
I will not shed tears while I write my code
I am currently working on trying to fix the problems I created when I tried to fix the problems
I created when I tried to fix the problems I created when ...
@returns a rectangle with the size inputted by users 
*/

#include <iostream>
using namespace std;

int main ()
{
    int width;
    cin >> width; 
    

    int height;
    cin >> height;
    cout << endl;

    for (int i = 0; i < height; i++)
    {
        for (int i = 0; i < width; i++)
        {
            cout << "*";
        }
        cout << endl;
    }
}
