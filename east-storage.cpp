/*
Author: Darren Moy 
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Lab 3 Task A 

Takes inputted date from the user and prints out the East basin storage on that day 

Gradescope is my life
I will document every single line of my code
I will not shed tears while I write my code
I am currently working on trying to fix the problems I created when I tried to fix the problems
I created when I tried to fix the problems I created when ...
@returns gallons of East basin storage of the date given by user 
*/

#include <iostream>
using namespace std;
#include <fstream>          //stream class; ofstreak/ifstream; create files, write info to files, read info from files
#include <cstdlib>          //c++ standard library header file 
#include <climits>          //header file consisting of min and max values of various data types 

int main()
{
    ifstream fin("Current_Reservoir_Levels.tsv");           
    if (fin.fail())
    {
        cerr << "File cannot be opened for reading." << endl;
        exit(1);
    }
            //open input file stream; represented by object ifstream, called fin 



    string junk;                                //Gets rid of the header line 
    getline(fin, junk);

    string date;
    cout << "Enter date: ";
    cin >> date;

    double eastSt;
    string date_in;
    while (fin >> date_in >> eastSt)            //reads file line by line
    {                                           //extracts 5 values each iteration 
        fin.ignore(INT_MAX, '\n');              //skips the the end of line, ignroes remaining columns 
        if (date_in == date)
        {
            cout << "East basin storage: " << eastSt << " billion gallons" << endl;
        }
    }
    fin.close();
    return 0;
}