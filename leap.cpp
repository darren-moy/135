/*
Author: Darren Moy 
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Lab C

Tells user if the inputted year is a leap year or a common year.

@return leap year or common year 
*/

#include <iostream>
using namespace std;

int main()
{
    const int LEAP_YEAR_DIVISOR = 4; // the first divisor to check if it's a leap year 
    const int SECOND_LEAP_YEAR_DIVISOR = 100; //the second divisor to check if it's a leap year 
    const int THIRD_LEAP_YEAR_DIVISOR = 400; //the third divisor to check if it's a leap year 
    int year;
    cout << "Enter year: ";
    cin >> year;

    if (year % LEAP_YEAR_DIVISOR != 0)
    {
        cout << "Common year";
    }   
    else if (year % SECOND_LEAP_YEAR_DIVISOR != 0)
    {
        cout << "Leap year";
    }
    else if (year % THIRD_LEAP_YEAR_DIVISOR != 0)
    {
        cout << "Common year";
    }
    else
    {
        cout << "Leap year";
    }
    return 0;
}