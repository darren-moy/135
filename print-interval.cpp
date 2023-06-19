/*
Author: Darren Moy 
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Lab 2 Task B

Takes two integers and prints out all integers in the range between them 

@return all of the integers between the two numbers but includes the lower range 
*/

#include <iostream>
using namespace std;

int main()
{
    int L;
    cout << "Please enter L: ";
    cin >> L;

    int U;
    cout << "Please enter U: ";
    cin >> U;

    int i;
    for (int i = L; i < U; i++)
    {
        cout << i << " ";
    }
    return 0;
}