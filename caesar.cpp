/*
Author: Darren Moy 
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Lab 6 Task B 

Returns the ciphertext of the sentence inputted from user 

Gradescope is my life
I will document every single line of my code
I will not shed tears while I write my code
I am currently working on trying to fix the problems I created when I tried to fix the problems
I created when I tried to fix the problems I created when ...
@returns string 
*/

#include <iostream>
#include <string>

using namespace std;

char shiftChar(char c, int rshift)
{
    int shifted, current;
    current = int(c);
    shifted = current + rshift;

    if ((shifted > 122 && current >= 'a' && current <= 'z') || (shifted > 90 && current >= 'A' && current <= 'Z'))
    {
        shifted -= 26;
    }

    else if (!isalpha(shifted))
    {
        shifted = current;
    }

    return shifted;
}

string encryptCaesar(string plaintext, int rshift)
{
    for (int i = 0; i < plaintext.length(); i++)
    {
        if ((int) plaintext[i] > 64 && (int)plaintext[i] < 123)
        {
            plaintext[i] = shiftChar(plaintext[i], rshift);
        }
    }

    return plaintext;
}

int main()
{
    string plaintext;
    cout << "Enter plaintext: ";
    getline(cin, plaintext);

    int shift;
    cout << "Enter Shift: ";
    cin >> shift;

    cout << encryptCaesar(plaintext, shift) << endl;

}
