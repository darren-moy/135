/*
Author: Darren Moy 
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Project 1B Task A 

Reads in a text file in terminal and then adds the integers within that text file 

Gradescope is my life
I will document every single line of my code
I will not shed tears while I write my code
I am currently working on trying to fix the problems I created when I tried to fix the problems
I created when I tried to fix the problems I created when ...
@returns the sum from the inputted text file 
*/

#include <iostream>
using namespace std;

int main()
{
    int x = 0;
    int sum = 0;
    while (cin >> x)
    {
     sum += x;   
    }

    cout << sum << endl;

    return 0;
}
