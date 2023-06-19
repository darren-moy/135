/*
Author: Darren Moy 
Course: CSCI-135
Instructor: Genady Maryash
Assignment: 

:

Gradescope is my life
I will document every single line of my code
I will not shed tears while I write my codeS
I am currently working on trying to fix the problems I created when I tried to fix the problems
I created when I tried to fix the problems I created when ...
@returns :
*/

#ifndef SKILL_HPP
#define SKILL_HPP
#include <string>

class Skill{
private:
    std::string name;
    std::string description;
    int totalUses;
    int specialty;

public:
    Skill();
    Skill(std::string name, std::string description, int specialty, int uses);
    std::string getName();
    std::string getDescription();
    int getTotalUses();
    int getSpecialty();
    std::string getSpecialty2();
    void setName(std::string name);
    void setDescription(std::string description);
    void setTotalUses(int uses);
    bool setSpecialty(int specialty);
};


#endif