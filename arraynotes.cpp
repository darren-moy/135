/*
Class notes for arrays 
*/

#include <iostream>
using namespace std;

int main()
{
    const int CAPACITY = 100;
    double values[CAPACITY];

    int size = 0;
    double input;
    while (cin >> input)
    {
        if (size < CAPACITY)
        {
            values[size] = input;
            size++;
        }
    }

    /*
    Printing elements in partially filled array: using current_size companion variable 
    */

    int current_size = 0;
    double input;
    while (cin >> input)
    {
        if (current_size < CAPACITY)
        {
            values[current_size] = input;
            current_size++;
        }
    }
    
        /* code for printing out the partial array */
    
    

    for (int i = 0; i < current_size; i++)
    {
        cout << values[i] << endl;
    }

    return 0;
}