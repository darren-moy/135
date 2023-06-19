/*
Author: Darren Moy 
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Quiz 1

A program that prints out the number of lines inputted from user to say I love C++
*/

#include <iostream>
using namespace std;

int main()
{
    int times;
    cout << "Enter a number: ";
    cin >> times;
    int i;
    for (i = 0; i < times; i++)
    {
        cout << "I love C++" << endl;
    }
    return 0;
}