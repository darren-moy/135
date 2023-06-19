#ifndef PRAC_HPP
#define PRAC_HPP
#include <string>

class Friend{
private:
    std::string firstname;
    std::string lastname;
    int height;
    int age;


public:
    Friend();
    Friend(std::string firstname, std::string lastname, int height, int age);
    std::string getfName;
    std::string getLName;
    int getHeight();
    int getAge();
    void setFname(std::string firstname);
    void setLname(std::string lastname);
    void setHeight(int height);
    void setAge(int age);
};

#endif