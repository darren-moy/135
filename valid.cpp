/*
Author: Darren Moy 
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Lab 2 Task A 

Takes inputted number ensuring that it is greater than 0 but less than 100 and then returns the number squared 

@return an integer between 0 and 100 squared 
*/

#include <iostream>
using namespace std;

int main()
{
    int number;
    cout << "Please enter an integer: ";
    cin >> number;

    while (number <= 0 || number >= 100)
    {
        cout << "Please re-enter: ";
        cin >> number;
    }
    
        number = number * number;
        cout << "Number squared is: " << number << endl;
    
    return 0;
}