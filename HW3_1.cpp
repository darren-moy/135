/*
Author: Darren Moy 
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Project 1B Task A 

Reads an integer and prints out whether it is negative, zero, or positive

Gradescope is my life
I will document every single line of my code
I will not shed tears while I write my code
I am currently working on trying to fix the problems I created when I tried to fix the problems
I created when I tried to fix the problems I created when ...
@returns the sign if the integer given 
*/

#include <iostream>
using namespace std;

int main()
{
    int num;
    cin >> num;
    if (num > 0)
    {
        cout << "The number is positive.";
    }
    if (num < 0)
    {
        cout << "The number is negative.";
    }
    if (num == 0)
    {
        cout << "The number is zero.";
    }
    return 0;
}
