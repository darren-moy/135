/*
Author: Darren Moy 
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Lab 3 Task A 

Takes in 2 days and returns the West basin elevation for all day in the intervals in reverse order 

Gradescope is my life
I will document every single line of my code
I will not shed tears while I write my code
I am currently working on trying to fix the problems I created when I tried to fix the problems
I created when I tried to fix the problems I created when ...
@returns West basin elevation for all days in reverse order 
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
    cout << "Enter earlier date: ";
    cin >> fdate;

    string edate;
    cout << "Enter later date: ";
    cin >> edate;

    string date[366];
    double west[366];

    string d;
    int counter = 0, counter2 = 0;
    double eastSt, eastEl, westEl, westSt;
   

    while (fin >> d >> eastSt >> eastEl >> westSt >> westEl) //reads file line by line
    {                                                     //extracts 5 values each iteration 
        fin.ignore(INT_MAX, '\n');

        if (d == fdate)
        {
            counter = 1;
        }

        if (counter == 1)
        {
            date[counter2] = d;
            west[counter2] = westEl;
            counter2++;
        }

        if (d == edate)
        {
            counter = 0;
        }
    }

    for (int i = counter2; i >= 0; i--)
    {
        cout << date[i] << " " << west[i] << " ft" << endl;
    }

    fin.close();
    return 0;
}