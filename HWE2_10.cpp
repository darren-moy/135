/*
Author: Darren Moy 
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Homework E2.10

Takes 3 inputs from the user and then calculates the cost per 100 miles and how far the car can go with the gas in the tank 

@return the cost per 100 miles and how many miles left the car can go 
*/

#include <iostream>
using namespace std;

int main()
{
    double tank_gal;
    cout << "Enter the number of gallons of gas in the tank: ";
    cin >> tank_gal;

    double mpg;
    cout << "Enter the fuel efficiency in miles per gallon: ";
    cin >> mpg;

    double price;
    cout << "Enter the price of gas per gallon: ";
    cin >> price;

    double price_per;
    price_per = (100 / mpg) * price;
    cout << price_per << endl;

    double howfar;
    howfar = mpg * tank_gal ;
    cout << howfar <<endl;

    return 0;
}