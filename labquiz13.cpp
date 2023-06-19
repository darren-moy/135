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

vector<int> makeVector(int n){
    vector<int> res;
    if (n == 0){
        return res;
    }

    for (int i = n; i >= 0; i--){
        res.push_back(i);
    }

    return res;
}

