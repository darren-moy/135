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

struct Post
{
    string username;
    string message;
};

class Network
{
private:
    static const int MAX_USERS = 20;
    int numUsers;
    Profile profiles[MAX_USERS];
    int findID(string usrn);
    bool following[MAX_USERS][MAX_USERS];
    static const int MAX_POSTS = 100; 
    int numPosts;                     
    Post posts[MAX_POSTS];            

public:
    Network()
    {
        numUsers = 0;
        numPosts = 0;
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
    bool writePost(string usrn, string msg);
    bool printTimeline(string usrn);
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

bool Network::follow(string usrn1, string usrn2)
{
    for (int i = 0; i < MAX_USERS; i++)
    {
        for (int j = 0; j < MAX_USERS; j++)
        {
            if (profiles[i].getUsername() == usrn1 && profiles[j].getUsername() == usrn2)
            {
                following[i][j] = true;
                return true;
            }
        }
    }
    return false;
}

void Network::printDot()
{
    cout << "digraph {" << endl;
    for (int i = 0; i < numUsers; i++)
    {
        cout << "  \"@" << profiles[i].getUsername() << "\"" << endl;
    }

    for (int i = 0; i < numUsers; i++)
    {
        for (int j = 0; j < numUsers; j++)
        {
            if (following[i][j])
            {
                cout << "  \"@" << profiles[i].getUsername() << "\" -> \"@" << profiles[j].getUsername() << "\"" << endl;
            }
        }
    }
    cout << "}";
}

bool Network::writePost(string usrn, string msg)
{
    if (findID(usrn) == -1 && numPosts > MAX_POSTS)
    {
        return false;
    }
    else
    {
        posts[numPosts].message = msg;
        posts[numPosts].username = usrn;
        numPosts++;
        return true;
    }

    return false;
}

bool Network::printTimeline(string usrn)
{
    Profile followlist[20];
    followlist[0] = profiles[findID(usrn)];
    int followers = 1;

    for (int j = 0; j < numUsers; j++)
    {
        if (following[findID(usrn)][j])
        {
            followlist[followers] = profiles[j];
            followers++;
        }
    }

    for (int i = numPosts; i >= 0; i--)
    {
        for (int j = 0; j < followers; j++)
        {
            if (posts[i].username == followlist[j].getUsername())
            {
                profiles[findID(usrn)];
                cout << followlist[j].getFullName() << ": " << posts[i].message << endl;
            }
        }
    }
    return 0;
}

int main() {
  Network nw;
  nw.addUser("mario", "Mario");
  nw.addUser("luigi", "Luigi");
  nw.addUser("yoshi", "Yoshi");
   
  nw.follow("mario", "luigi");
  nw.follow("luigi", "mario");
  nw.follow("luigi", "yoshi");
  nw.follow("yoshi", "mario");

  nw.writePost("mario", "It's a-me, Mario!");
  nw.writePost("luigi", "Hey hey!");
  nw.writePost("mario", "Hi Luigi!");
  nw.writePost("yoshi", "Test 1");
  nw.writePost("yoshi", "Test 2");
  nw.writePost("luigi", "I just hope this crazy plan of yours works!");
  nw.writePost("mario", "My crazy plans always work!");
  nw.writePost("yoshi", "Test 3");
  nw.writePost("yoshi", "Test 4");
  nw.writePost("yoshi", "Test 5");

  cout << endl;
  cout << "======= Mario's timeline =======" << endl;
  nw.printTimeline("mario");
  cout << endl;

  cout << "======= Yoshi's timeline =======" << endl;
  nw.printTimeline("yoshi");
  cout << endl;
}