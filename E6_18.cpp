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
#include <math.h>
#include <vector>
using namespace std;

vector<int> append(vector<int> a, vector<int> b){
    vector<int> res;
    for (int i = 0; i < a.size(); i++){
        res.push_back(a[i]);
    }

    for (int i = 0; i < b.size(); i++){
        res.push_back(b[i]);
    }

    return res;
}