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

string addtabs(int t){
    string newx = "";
    for (int i = 0; i < t; i++){
        newx += "\t";
    }
    return newx;
}

int countChar(string line, char c){
    int d = 0;
    for (int i = 0; i < line.length(); i++){
        if (line[i] == c){
            d++;
        }
    }
    return d;
}

int main(){
    string x;
    int in = 0;

    while (getline(cin,x)){
        x = removeLeadingSpaces(x);
        int c;
        if (x[0] == '}'){
            c = 1;
        }
        else{
            c = 0;
        }
        cout << addtabs(in-c) << x << endl;
        in += countChar(x, '{') - countChar(x, '}');
    }

    return 0;
}
