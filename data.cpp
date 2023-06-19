/*
Author: Darren Moy 
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Lab quiz 4



Gradescope is my life
I will document every single line of my code
I will not shed tears while I write my code
I am currently working on trying to fix the problems I created when I tried to fix the problems
I created when I tried to fix the problems I created when ...
@returns : the text file after reading it 
*/

#include <iostream>
using namespace std;
#include <fstream>          //stream class; ofstreak/ifstream; create files, write info to files, read info from files
#include <cstdlib>          //c++ standard library header file 
#include <climits>

int main()
{
    ifstream fin("data.txt");

    string color;
    string hex;
    while (fin >> color >> hex)
    {
        cout << color << " " << hex << endl;

    }
    fin.close();
    return 0;
}
