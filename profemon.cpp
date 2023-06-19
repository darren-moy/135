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
#include "profemon.hpp"

Profemon::Profemon(){
    this->name = "Undefined";
    this->current_xp;
    this->max_health;
    this->required_xp;
    this->specialty;
    this->level;
    Skill skills[] = { Skill(), Skill(), Skill() };
}

Profemon::Profemon(std::string name, double max_health, Specialty specialty){
    this->name = name;
    this->current_xp = 0;
    this->max_health = max_health;
    this->required_xp = 50;
    this->specialty = specialty;
    this->level = 0;
    Skill skills[] = { Skill(), Skill(), Skill() };
}

std::string Profemon::getName(){
    return name;
}

Specialty Profemon::getSpecialty(){
    return specialty;
}

std::string Profemon::getSpecialty2(){
    std::string res;
    if (specialty == 0){
        res = "ML";
    }
    else if (specialty == 1){
        res = "SOFTWARE";
    }
    else if (specialty == 2){
        res = "HARDWARE";
    }

    return res;
}

int Profemon::getLevel(){
    return level;
}

double Profemon::getMaxHealth(){
    return max_health;
}

void Profemon::setName(std::string name){
    this->name = name;
}

void Profemon::levelUp(int exp)
{
    current_xp += exp;
    while (current_xp >= required_xp)
    {
        current_xp -= required_xp;
        level++;
        if (specialty == 0){
            required_xp += 10;
        }
        else if (specialty == 1){
            required_xp += 15;
        }
        else{
            required_xp += 20;
        }
    }
}

bool Profemon::learnSkill(int slot, Skill skill){

    if ((slot == 0) || (slot == 1) || (slot == 2)){
        if (getSpecialty() == skill.getSpecialty()){
            skills[slot] = skill;
            return true;
        }

        else{
            return false;
        }
    }

    else{
        return false;
    }
} 

void Profemon::printProfemon(bool print_skills)
{
    std::string types[] = {"ML", "SOFTWARE", "HARDWARE"};
    std::cout << getName() + " [" << getSpecialty2() << "] | lvl " << getLevel() << " | exp " << current_xp << '/' << required_xp << " | hp " << getMaxHealth() << std::endl;

    if(print_skills){
        for(int i = 0; i < 3; i++){
            if(skills[i].getName() != "Undefined"){
                Skill skill = skills[i];
                std::cout << "    " << skill.getName() << " [" << skill.getTotalUses() << "] : " << skill.getDescription() << std::endl;
            }
        }
    }
}
