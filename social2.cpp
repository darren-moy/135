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
    void setUsername(string usrn);
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

void Profile::setUsername(string usrn){
    username = usrn;
}

class Network {
private:
  static const int MAX_USERS = 20; // max number of user profiles
  int numUsers;                    // number of registered users
  Profile profiles[MAX_USERS];     // user profiles array:
                                   // mapping integer ID -> Profile

  // Returns user ID (index in the 'profiles' array) by their username
  // (or -1 if username is not found)
  int findID (string usrn);
public:
  // Constructor, makes an empty network (numUsers = 0)
  Network();
  // Attempts to sign up a new user with specified username and displayname
  // return true if the operation was successful, otherwise return false
  bool addUser(string usrn, string dspn);
};

int Network::findID (string usrn){
    int res = -1;
    for (int i = 0; i < MAX_USERS; i++){
        if (usrn == profiles[i].getUsername()){
            res = i;
        }
        else{
            res = -1;
        }
    }
    return res;
}

bool Network::addUser(string usrn, string dspn){
    for (int i = 0; i < usrn.length(); i++){
        if (!isalnum(usrn[i])){
            return false;
        }
    }

    if (!usrn.empty() && findID(usrn) != -1 && numUsers < 20){
        profiles[numUsers].setDisplayName(dspn);
        profiles[numUsers].setUsername(usrn);
        numUsers += 1;
        return true;
    }
    else{
        return false;
    }

}

int main(){
  Network nw;
  cout << nw.addUser("mario", "Mario") << endl;     // true (1)
  cout << nw.addUser("luigi", "Luigi") << endl;     // true (1)

  cout << nw.addUser("mario", "Mario2") << endl;    // false (0)
  cout << nw.addUser("mario 2", "Mario2") << endl;  // false (0)
  cout << nw.addUser("mario-2", "Mario2") << endl;  // false (0)

  for(int i = 2; i < 20; i++)
      cout << nw.addUser("mario" + to_string(i), 
                 "Mario" + to_string(i)) << endl;   // true (1)

  cout << nw.addUser("yoshi", "Yoshi") << endl;     // false (0)
}
