/*
Author: Darren Moy 
Course: CSCI-135
Instructor: Genady Maryash
Assignment: 

Write fnc void that reveices two pointers and sorts the values to which they point. 
if you call sort2(&p, &q) then p <= q after the call 

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
#include <cctype>
#include <climits>
#include <stdlib.h>
#include <math.h>
using namespace std;

void sort2(double* p, double* q){
    if ((*p > *q)){
        double x = *p;
        *p = *q;
        *q = x;
    }

}

int main(){
    return 0;
}