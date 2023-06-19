/*
Author: Darren Moy
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Lab 11

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

class Profile
{
private:
    string username;
    string displayname;

public:
    Profile(string usrn, string dspn)
    {
        username = usrn;
        displayname = dspn;
    }
    Profile();
    string getUsername();
    string getFullName();
    void setDisplayName(string dspn);
};

string Profile::getUsername()
{
    return username;
}
string Profile::getFullName()
{
    string newname;
    newname = displayname + "(@" + username + ")";
    return newname;
}

void Profile::setDisplayName(string dspn){
    displayname = dspn;
}

int main() {
    Profile p1("marco", "Marco");
    cout << p1.getUsername() << endl; 
    cout << p1.getFullName() << endl; 

    p1.setDisplayName("Marco Rossi");
    cout << p1.getUsername() << endl; 
    cout << p1.getFullName() << endl; 

    Profile p2("tarma1", "Tarma Roving");
    cout << p2.getUsername() << endl; 
    cout << p2.getFullName() << endl; 
}
