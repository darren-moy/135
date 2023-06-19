/*
Author: Darren Moy 
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Lab 4 Task B 

Takes user input of width and height and prints out a checkerboard of 3x3 squares 

Gradescope is my life
I will document every single line of my code
I will not shed tears while I write my code
I am currently working on trying to fix the problems I created when I tried to fix the problems
I created when I tried to fix the problems I created when ...
@returns a checkerboard full of 3x3 squares 
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
    int x;
    cout << "Input width: " << endl;
    cin >> x;

    int y;
    cout << "Input height: " << endl;
    cin >> y;

    string res = "";
    for (int i = 0; i < y; ++i) {
        for (int j = 0, c = '*'; j < x; ++j, c = '*') {
            if (((j / 3) & 1) ^ ((i / 3) & 1))
                c = ' ';

            res += (char)c;
        }

        res += '\n';
    }

    cout << res;
    return 0;
}