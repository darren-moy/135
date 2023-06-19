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

#ifndef PROFEMON_HPP
#define PROFEMON_HPP

#include <string>
#include "skill.hpp"

enum Specialty{
    ML,
    SOFTWARE,
    HARDWARE
};

class Profemon{
private:
    std::string name;
    int level;
    int required_xp;
    int current_xp;
    double max_health;
    Specialty specialty;
    std::string Specialty2;
    Skill skills[3];
    
public: 
    Profemon();
    Profemon(std::string name, double max_health, Specialty specialty);
    std::string getName();
    Specialty getSpecialty();
    int getLevel();
    double getMaxHealth();
    void setName(std::string name);
    void levelUp(int exp);
    bool learnSkill(int slot, Skill skill);
    void printProfemon(bool print_skills);
    std::string getSpecialty2();
};

#endif
