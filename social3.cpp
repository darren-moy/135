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
    string displayname;
    string username;

public:
    Profile(string usrn, string dspn)
    {
        username = usrn;
        displayname = dspn;
    }
    Profile()
    {
        username = "";
        displayname = "";
    }
    string getUsername();
    string getFullName();
    void setDisplayName(string dspn);
    void setUserName(string usrn);
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
void Profile::setDisplayName(string dspn)
{
    displayname = dspn;
}
void Profile::setUserName(string usrn)
{
    username = usrn;
}

class Network
{
private:
    static const int MAX_USERS = 20;
    int numUsers;
    Profile profiles[MAX_USERS];
    int findID(string usrn);
    bool following[MAX_USERS][MAX_USERS];

public:
    Network()
    {
        numUsers = 0;
        for (int i = 0; i < MAX_USERS; i++)
        {
            for (int j = 0; j < MAX_USERS; j++)
            {
                following[i][j] = false;
            }
        }
    }
    bool addUser(string usrn, string dspn);
    // Make 'usrn1' follow 'usrn2' (if both usernames are in the network).
    // return true if success (if both usernames exist), otherwise return false
    bool follow(string usrn1, string usrn2);

    // Print Dot file (graphical representation of the network)
    void printDot();
};

int Network::findID(string usrn)
{
    for (int i = 0; i < 20; i++)
    {
        if (usrn == profiles[i].getUsername())
        {
            return i;
        }
    }

    return -1;
}

bool Network::addUser(string usrn, string dspn)
{

    for (int i = 0; i < usrn.length(); i++)
    {
        if (!isalnum(usrn[i]))
        {
            return false;
        }
    }

    if (!usrn.empty() && findID(usrn) == -1 && numUsers < 20)
    {
        profiles[numUsers].setDisplayName(dspn);
        profiles[numUsers].setUserName(usrn);
        numUsers = numUsers + 1;
        return true;
    }
    else
    {
        return false;
    }
}

bool Network::follow(string usrn1, string usrn2){
    for (int i = 0; i < MAX_USERS; i ++){
        for (int j = 0; j < MAX_USERS; j++){
            if (profiles[i].getUsername() == usrn1 && profiles[j].getUsername() == usrn2){
                following[i][j] = true;
                return true;
            }
        }
    }
    return false;
}

void Network::printDot(){
    cout << "digraph {" << endl;
    for (int i = 0; i < numUsers; i++){
        cout << "  \"@" << profiles[i].getUsername() << "\"" << endl;
    }

    for (int i = 0; i < numUsers; i++){
        for (int j = 0; j < numUsers; j++){
            if(following[i][j]){
                cout << "  \"@" << profiles[i].getUsername() << "\" -> \"@" << profiles[j].getUsername() << "\""<< endl;
            }
        }
    }
    cout << "}";
}

int main() {
    Network nw;
    nw.addUser("mario", "Mario");
    nw.addUser("luigi", "Luigi");
    nw.addUser("yoshi", "Yoshi");

    nw.follow("mario", "luigi");
    nw.follow("mario", "yoshi");
    nw.follow("luigi", "mario");
    nw.follow("luigi", "yoshi");
    nw.follow("yoshi", "mario");
    nw.follow("yoshi", "luigi");

    nw.addUser("wario", "Wario");
    
    for(int i = 2; i < 6; i++) {
        string usrn = "mario" + to_string(i);
        string dspn = "Mario " + to_string(i);
        nw.addUser(usrn, dspn);
        nw.follow(usrn, "mario");
    }
    nw.follow("mario2", "luigi");

    nw.printDot();
}