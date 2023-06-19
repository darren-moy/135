/*
Author: Darren Moy 
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Project 1B Task A 

Evaluates multiple arithmetic expressions 
Gradescope is my life
I will document every single line of my code
I will not shed tears while I write my code
I am currently working on trying to fix the problems I created when I tried to fix the problems
I created when I tried to fix the problems I created when ...
@returns the result of the 
*/ 

#include <iostream>
using namespace std;

int main()
{
    int x;
    int result = 0;
    char sign = '+';
    char old;

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

        old = sign;
        cin >> sign;

        if (sign == '^')
        {
            if (old == '+')
            {
                result -= x;
                x = x * x;
                result += x;
            }
            else
            {
                result += x;
                x = x * x;
                result -= x;
            }
            cin >> sign;
        }

        if (sign == ';')
        {
            cout << result << endl;
            result = 0;
            sign = '+';
        }
    }

    return 0;
}