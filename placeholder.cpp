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

class Profile{
private:
  string displayname;
  string username;

public:
  Profile(string usrn, string dspn){
    username = usrn;
    displayname = dspn;
  }
  Profile(){
    username = "";
    displayname = "";
  }
  string getUsername();
  string getFullName();
  void setDisplayName(string dspn);
  void setUserName(string usrn);
};

string Profile::getUsername(){
  return username;
}
string Profile::getFullName(){
  string newname;
  newname = displayname + "(@" + username + ")";
  return newname;
}
void Profile::setDisplayName(string dspn){
  displayname = dspn;
}
void Profile::setUserName(string usrn){
  username = usrn;
}

class Network {
private:
  static const int MAX_USERS = 20;
  int numUsers;
  Profile profiles[MAX_USERS];
  int findID (string usrn);

public:
  Network(){
    numUsers = 0;
  }
  bool addUser(string usrn, string dspn);

};


int Network::findID(string usrn){
  for(int i = 0;i < 20;i++){
    if(usrn == profiles[i].getUsername()){
      return i;
    }
  }

  return -1;

}

bool Network::addUser(string usrn, string dspn){

  for(int i = 0; i < usrn.length();i++){
    if(!isalnum(usrn[i])){
      return false;
    }
  }

  if(!usrn.empty() && findID(usrn)==-1 && numUsers < 20){
    profiles[numUsers].setDisplayName(dspn);
    profiles[numUsers].setUserName(usrn);
    numUsers = numUsers + 1;
    return true;
  }
  else{
    return false;

  }
}


int main() {
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