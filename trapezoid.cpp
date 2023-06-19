/*
Author: Darren Moy 
Course: CSCI-135
Instructor: Genady Maryash
Assignment: 

Prints an upside down trapezoid of given width and height

Gradescope is my life
I will document every single line of my code
I will not shed tears while I write my code
I am currently working on trying to fix the problems I created when I tried to fix the problems
I created when I tried to fix the problems I created when ...
@returns an upside down trapezoid
*/

#include <iostream>
using namespace std;

int main()
{
    int width;
    cout << "Input width: ";
    cin >> width;

    int height;
    cout << "Input height: ";
    cin >> height;

    int spaces = 0;
    int stars = width;
    int z = 0; 

    if (width-(height*2) < -1)
    {
        cout << "Impossible shape!" << endl;
    }
        
    else
    {
        cout << "Shape: " << endl;
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < spaces; j++)
            {
                cout << " ";
            }

            for (int k = 0; k < stars; k++)
            {
                cout << "*";
            }

            cout << endl;
            spaces += 1;
            stars -= 2;
        }
    }

    return 0;
}
