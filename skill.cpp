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

#include "skill.hpp"

Skill::Skill(){                 //private vars being set 
    name = "Undefined";
    description = "Undefined";
    totalUses = -1;
    specialty = -1;
}

Skill::Skill(std::string name, std::string description, int specialty, int uses){
    this->name = name;                //assigns the value of the name parameter   
    this->description = description;  //passed to the constructor to the name
    this->specialty = specialty;      //private member var of the object being constructed
    this->totalUses = uses;
}

std::string Skill::getName(){
    return name;
}

std::string Skill::getDescription(){
    return description;
}

int Skill::getTotalUses(){
    return totalUses;
}

int Skill::getSpecialty(){
    return specialty;
}


void Skill::setName(std::string name){
    this->name = name;
}

void Skill::setDescription(std::string description){
    this->description = description;
}

void Skill::setTotalUses(int uses){
    this->totalUses = uses;
}

bool Skill::setSpecialty(int specialty){
    if (specialty == 0 || specialty == 1 || specialty == 2){
        this->specialty = specialty;
        return true;
    }

    return false;
}

