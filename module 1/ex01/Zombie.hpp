#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie
{
private:
    std::string name;

public:
    // Default constructor
    Zombie(void) { this->name = ""; }
    // Parameterized constructor (Must be explicitly called)
    Zombie(std::string name) { this->name = name; }
    void setName(std::string name);
    ~Zombie();
    void announce(void);
};

#endif