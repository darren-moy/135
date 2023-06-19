/*
Author: Darren Moy 
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Lab 2 Task D

Uses an array of ints to compute and print all Fibonacci numbers from F(0) to F(59)
Gradescope is my life
I will document every single line of my code
I will not shed tears while I write my code
I am currently working on trying to fix the problems I created when I tried to fix the problems
I created when I tried to fix the problems I created when ...
@returns all fibonacci numbers frm 0 - 59
*/

#include <iostream>
using namespace std;

int main()
{
    int fib[60];
    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i < 60; i++)
    {
        fib[i] = fib[i-1] + fib[i-2];
    }

    for (int i = 0; i < 60; i++)
    {
        cout << fib[i] << endl;
    }

    return 0;
}

/*
Note: returns negative nums because of integer overflow; hits max/min memory bounds 
*/