/*
Author: Darren Moy 
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Lab A

Asks the users to input two integer numbers and prints out the smaller of the two.
*/


#include <iostream>
using namespace std;

int main(){
    int first, second;
    cout << "Enter the first number: ";
    cin >> first;
    cout << "Enter the second number: ";
    cin >> second;
    if (first < second){
        cout << "The smaller of the two is " << first << endl;
    }
    else{
        cout << "The smaller of the two is " << second << endl;
    }
    return 0;
}