/*
Author: Darren Moy 
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Project 1B Task A 

Reads three nums and returns wheter it is increasing, decreasing order or neither 

Gradescope is my life
I will document every single line of my code
I will not shed tears while I write my code
I am currently working on trying to fix the problems I created when I tried to fix the problems
I created when I tried to fix the problems I created when ...
@returns whether the numbers are increasing, decreasing, or neither 
*/

#include <iostream>
using namespace std;

int main()
{
    int first;
    cin >> first;
    int second;
    cin >> second;
    int third;
    cin >> third;

    if (first > second)
    {
        if (second > third)
        {
            cout << "decreasing";
        }
        else
        {
            cout << "neither";
        }
    }   

    else if (second > first)
    {
        if (third > second)
        {
            cout << "increasing";
        }
        else 
        {
            cout << "neither";
        }
    } 

    else 
    {
        cout << "neither";
    }
    
    return 0;
}