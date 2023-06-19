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

vector<int> merge_sorted(vector<int> a, vector<int> b){
    vector<int> res;
    int Asize = 0;
    int Bsize = 0;

    while (Asize < a.size() && Bsize < b.size()){
        if (a[Asize] < b[Bsize]){
            res.push_back(a[Asize]);
            Asize++;
        }
        else{
            res.push_back(b[Bsize]);
            Bsize++;
        }
    }

    while (Asize < a.size()){
        res.push_back(a[Asize]);
        Asize++;
    }

    while (Bsize < b.size()){
        res.push_back(b[Bsize]);
        Bsize++;
    }
    

    return res;
}