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
using namespace std;

class Rectangle{
public:

    Rectangle(float w, float h){
        height = h;
        width = w;
    }
    float get_perimeter(){
        return (2 * height) + (2 * width);
    }

    float get_area(){
        return height * width;
    }

    void resize(double factor){
        height = height * factor;
        width = width * factor;
    }

private:
    float height;
    float width;
};

int main(){
    return 0;
}