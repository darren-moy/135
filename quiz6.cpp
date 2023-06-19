/*
Author: Darren Moy 
Course: CSCI-135
Instructor: Genady Maryash
Assignment: 

Lab quiz 6 

Gradescope is my life
I will document every single line of my code
I will not shed tears while I write my code
I am currently working on trying to fix the problems I created when I tried to fix the problems
I created when I tried to fix the problems I created when ...
@returns returns the maximum of the three 
*/

#include <iostream>
using namespace std;

int max3(int a, int b, int c)
{
    if (a > b)
    {
        if (a > c)
        {
            return a;
        }

        else
        {
            return c;
        }
    }
    else
    {
        return b;
    }

    
    return 0;
}
