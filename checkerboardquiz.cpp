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

int main()
{
    int img[MAX_H][MAX_W];
    int h, w;

    readImage(img, h, w);
    int out[MAX_H][MAX_W];
    for (int row = 0; row < h; row++)
    {
        for (int col = 0; col < w; col++)
        {
            if ((row) % 2 == 0)
            {
                if ((col) % 2 == 0)
                {
                    out[row][col] = img[row][col];
                }
                else
                {
                    out[row][col] = 0;
                }
            }
            else
            {
                if ((col) % 2 == 0)
                {
                    out[row][col] = 0;
                }
                else
                {
                    out[row][col] = img[row][col];
                }
            }
        }
    }
    writeImage(out, h, w);
    return 0;
}
