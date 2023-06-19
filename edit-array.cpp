/*
Author: Darren Moy 
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Lab 2 Task C

Creates an array of 10 integers and allows the user to edit any of them 
Gradescope is my life
I will document every single line of my code
I will not shed tears while I write my code
I am currently working on trying to fix the problems I created when I tried to fix the problems
I created when I tried to fix the problems I created when ...
@return all of the integers between the two numbers but includes the lower range 
*/

#include <iostream>
using namespace std;

int main()
{
    int myData[10];
    int i;
    for (int i = 0; i < 10; i++)
    {
        myData[i] = 1;
    }

    do 
    {
        for (int i = 0; i < 10; i++)
        {
            cout << myData[i] << " ";
        }

        cout << endl << "Input index: ";
        cin >> i;

        int v;
        cout << endl <<"Input value: ";
        cin >> v;

        if (i < 10 && i >= 0)
        {
            myData[i] = v;
        }
    }while (i < 10 && i >= 0);

    cout << "Index out of range. Exit.";  

    return 0;
}