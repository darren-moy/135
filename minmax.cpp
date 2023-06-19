/*
Author: Darren Moy 
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Lab 3 Task A 

Gets the minimum and maximum storage of East basin in 2016

Gradescope is my life
I will document every single line of my code
I will not shed tears while I write my code
I am currently working on trying to fix the problems I created when I tried to fix the problems
I created when I tried to fix the problems I created when ...
@returns the minimum and maximum 
*/

#include <iostream>
using namespace std;
#include <fstream>
#include <cstdlib>
#include <climits>

int main()
{
    ifstream fin("Current_Reservoir_Levels.tsv");
    if (fin.fail())
    {
        cerr << "File cannot be opened for reading." << endl;
        exit(1);
    }

    string junk;                                    //Gets rid of the header line 
    getline(fin, junk);
    
    double eastSt, min = -1, max = 0;
    string date_in;
    while (fin >> date_in >> eastSt) //reads file line by line
    {                                                     //extracts 5 values each iteration 
        fin.ignore(INT_MAX, '\n');
        if (min > eastSt or min == -1)
        {
            min = eastSt;
        }
        if (max < eastSt)
        {
            max = eastSt;
        }
    }   

    cout << "minimum storage in East basin: " << min << " billion gallons" << endl;
    cout << "MAXimum storage in East basin: " << max << " billion gallons" << endl;

    fin.close();
    return 0;
}