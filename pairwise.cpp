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

vector<int> sumPairWise(vector<int> &v1, vector<int> &v2){
    vector<int> res;
    int maxv = max(v1.size(), v2.size());
    int minv = min(v1.size(), v2.size());

    if (v1.size() > v2.size()){
        do{
            v2.push_back(0);
        }
        while(v1.size() != v2.size());

    }

    if (v1.size() < v2.size()){
        do{
            v1.push_back(0);
        }
        while(v1.size() != v2.size());

    }

    for (int i = 0; i < maxv; i++){
        int sum = v1[i] + v2[i];
        res.push_back(sum);
    }

    return res;
}