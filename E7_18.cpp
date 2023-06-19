/*
Author: Darren Moy
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Project 2 C

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

class Point {
public: 
    double x;
    double y;
};

double distance (Point a, Point b){
    double x = b.x - a.x;
    double y = b.y - a.y;

    double dist = sqrt(pow(x,2) + pow (y,2));

    return dist;
}

class Triangle{
public:
    Point a;
    Point b;
    Point c;
};

double perimeter(Triangle dist){
    double side1 = distance(dist.a, dist.b);
    double side2 = distance(dist.b, dist.c);
    double side3 = distance(dist.c, dist.a);
    return side1 + side2 + side3;
}