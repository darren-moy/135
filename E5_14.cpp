/*
Author: Darren Moy 
Course: CSCI-135
Instructor: Genady Maryash
Assignment: E 5.14

Function that swaps 2 integers if a is greater than b 

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

void sort2(int& a, int& b)
{
    int placeholder = 0;
    if (a > b)
    {
       placeholder = a;
       a = b;
       b = placeholder;
    }
}
