/*
Author: Darren Moy 
Course: CSCI-135
Instructor: Genady Maryash
Assignment: HW 8.1

:

Gradescope is my life
I will document every single line of my code
I will not shed tears while I write my code
I am currently working on trying to fix the problems I created when I tried to fix the problems
I created when I tried to fix the problems I created when ...
@returns :
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
using namespace std;

int main(){
    ofstream fout;
    fout.open("hello.txt");

    fout << "Hello, World!";
    fout.close();

    ifstream fin;
    fin.open("hello.txt");
    string str;
    getline(fin,str);
    cout << str;
    fin.close();

    return 0;
}