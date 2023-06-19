/*
Author: Darren Moy 
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Project 1B Task A 

Reads in a text file and computes the given equation 

Gradescope is my life
I will document every single line of my code
I will not shed tears while I write my code
I am currently working on trying to fix the problems I created when I tried to fix the problems
I created when I tried to fix the problems I created when ...
@returns the answer of an equation given in a text file 
*/ 

#include <iostream>
using namespace std;

int main()
{
    int x;
    int result = 0;
    char sign = '+';

    while (cin >> x)
    {
        if (sign == '+')
        {
            result += x;
        }
        else if (sign == '-')
        {
            result -= x;
        }
        cin >> sign;
    }
    cout << result << endl;
    return 0;
}