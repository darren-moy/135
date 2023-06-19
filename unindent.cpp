/*
Author: Darren Moy 
Course: CSCI-135
Instructor: Genady Maryash
Assignment: 

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
#include <cctype>
#include <climits>
#include <stdlib.h>
using namespace std;

string removeLeadingSpaces (string line){
    string res = "";
    bool foundchar = false;
    for (char c : line){
        if (!foundchar && isspace(c)){
            continue;
        }
        foundchar = true;
        res += c;
    }
    return res;
}

int main(){
    string inp;
    while (getline(cin, inp)){
        cout << removeLeadingSpaces(inp) << endl;
    }
    return 0;
}
