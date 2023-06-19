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

int main ()
{
    int first, second;
    cout << "Enter the first number: ";
    cin >> first;
    cout << "Enter the second number: ";
    cin >> second;
    if (first > second){
        cout << "The larger of the two is " << first << endl;
    }
    else{
        cout << "The larger of the two is " << second << endl;
    }
    return 0;
}