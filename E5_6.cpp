/*
Author: Darren Moy 
Course: CSCI-135
Instructor: Genady Maryash
Assignment: HW E5.6

:

Gradescope is my life
I will document every single line of my code
I will not shed tears while I write my code
I am currently working on trying to fix the problems I created when I tried to fix the problems
I created when I tried to fix the problems I created when ...
@returns :
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include <stdlib.h>
using namespace std;

string middle(string str)
{
    if (str.length() % 2 == 1)
    {
        return str.substr(str.length()/2, 1);
    }

    else
    {
        return str.substr(str.length()/2-1, 2);
    }
}