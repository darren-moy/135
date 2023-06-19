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

    return shifted;
}

string encryptVigenere(string plaintext,string keyword){
  int c = 0;
  string x;
  for(int i = 0;i < plaintext.length();i++){
    int num = plaintext[i];
    if(isalpha(plaintext[i])){
      x += shiftChar(num,((int)keyword[(c%keyword.length())]-97));
      c++;
    }
    else{
      x+=plaintext[i];
    }
  }
  return x;
}

int main()
{
    string plaintext;
    cout << "Enter plaintext: ";
    getline(cin, plaintext);

    string keyword;
    cout << "Enter Keyword: ";
    cin >> keyword;

    cout << encryptVigenere(plaintext, keyword);
    return 0;
}
