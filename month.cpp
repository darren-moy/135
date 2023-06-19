/*
Author: Darren Moy 
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Lab D

Prints the number of days in the user-inputted year and month 

@return the number of days in the month given 
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
    int month;
    cout << "Enter month: ";
    cin >> month;
    string result;

    if (year % LEAP_YEAR_DIVISOR != 0)
    {
        result = "Common year";
    }   
    else if (year % SECOND_LEAP_YEAR_DIVISOR != 0)
    {
        result = "Leap year";
    }
    else if (year % THIRD_LEAP_YEAR_DIVISOR != 0)
    {
        result = "Common year";
    }
    else
    {
        result = "Leap year";
    }
    
    if (result == "Leap year")
    {
        if (month == 2)
        {
            cout << "29 days";
        }
        else if (month < 9 && month % 2 != 0)
        {
            cout << "31 days";
        }
        else if (month == 10 || month == 12 || month == 8)
        {
            cout << "31 days";
        }
        else
        {
            cout << "30 days";
        }
    }

    if (result == "Common year")
    {
        if (month == 2)
        {
            cout << "28 days";
        }
        else if (month < 9 && month % 2 != 0)
        {
            cout << "31 days";
        }
        else if (month == 10 || month == 12 || month == 8)
        {
            cout << "31 days";
        }
        else
        {
            cout << "30 days";
        }
    }
    return 0;
}
