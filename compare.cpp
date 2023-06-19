/*
Author: Darren Moy 
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Lab 3 Task A 

Takes in 2 days and returns which basin had the higher elevaton on each of the days within the interval

Gradescope is my life
I will document every single line of my code
I will not shed tears while I write my code
I am currently working on trying to fix the problems I created when I tried to fix the problems
I created when I tried to fix the problems I created when ...
@returns East, West, or Neither 
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

    string fdate;
    cout << "Enter starting date: ";
    cin >> fdate;

    string edate;
    cout << "Enter ending date: ";
    cin >> edate;

    string d;
    int counter = 0;
    double eastEl, westEl, eastSt, westSt;
    while (fin >> d >> eastSt >> eastEl >> westSt >> westEl) //reads file line by line
    {                                                     //extracts 5 values each iteration 
        fin.ignore(INT_MAX, '\n');
        if (d == fdate)
        {
            counter = 1;
        }

        if (counter == 1)
        {
            if (eastEl > westEl)
            {
                cout << d << " East" << endl;
            }
            else if (eastEl < westEl)
            {
                cout << d << " West" << endl;
            }
            else 
            {
                cout << d << " Equal" << endl;
            }

        if (d == edate)
        {
            counter = 0;
        }
        }
    }
    fin.close();
    return 0;
}