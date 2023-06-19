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
#include <fstream>
#include <cstdlib>
#include <cctype>
#include <climits>
#include <stdlib.h>
#include <math.h>
using namespace std;

class Circuit {
public:
    int get_first_switch_state(){
        return fswitch;
    }

    int get_second_switch_state(){
        return sswitch;
    }

    int get_lamp_state(){
        return lamp;
    }

    void toggle_first_switch(){
        if (fswitch){
            fswitch = 0;
        }
        else{
            fswitch = 1;
        }

        if (lamp){
            lamp = 0;
        }
        else{
            lamp = 1;
        }
    } 
    
    void toggle_second_switch(){
        if (sswitch){
            sswitch = 0;
        }
        else{
            sswitch = 1;
        }

        if (lamp){
            lamp = 0;
        }
        else{
            lamp = 1;
        }
    }

private:
    int fswitch = 0;
    int sswitch = 0;
    int lamp;
};

