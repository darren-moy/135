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

class Money{
public:
    int dollars;
    int cents;
};

Money withdraw_money(Money balance, Money withdrawal){
    Money ending;
    ending.dollars = balance.dollars - withdrawal.dollars;
    ending.cents = balance.cents - withdrawal.cents;
    if (0 > ending.cents){
        ending.dollars -= 1;
        ending.cents += 100;
    }
    if (0 > (ending.dollars + (ending.cents * .01))){
        ending.dollars = 0;
        ending.cents = .00;
    }

    return ending;
}