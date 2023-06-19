/*
Author: Darren Moy 
Course: CSCI-135
Instructor: Genady Maryash
Assignment: 

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
#include <cctype>
#include <climits>
#include <stdlib.h>
#include <math.h>
using namespace std;

class Date{
    public:
    int month;
    int day;
    int year;
};

string formatDate(Date * d){
    string months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    int index = d->year;
    string act_month = months[index];
    string res;
    res += months [d->month]; 
    res += " ";
    res += d->day;
    res += ", ";
    res += d->year;

    return res;
    
}

int main(){
    return 0;
}