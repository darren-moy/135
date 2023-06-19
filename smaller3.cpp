/*
Author: Darren Moy 
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Lab B

Takes the smallest of three numbers taken from user's input.

@return the smallest of the three numbers 
*/

#include <iostream>
using namespace std;

int main()
{
    int x;
    cout << "Enter the first number: ";
    cin >> x;
    int y;
    cout << "Enter the second number: ";
    cin >> y;
    int z;
    cout << "Enter the third number: ";
    cin >> z;
    if (x > y)
    {
        if (y > z)
        {
            cout << "The smaller of the three is " << z << endl;
        }
        else
        {
            cout << "The smallest of the three is " << y << endl;
        }
    }
    else 
    {
        if (x > z)
        {
            cout << "The smaller of the three is " << z << endl;
        }
        else
        {
            cout << "The smallest of the three is" << x << endl;
        }
    }
    return 0;
}