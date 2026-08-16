#include "Zombie.hpp"

Zombie::~Zombie()
{
    std::cout << name << " object destroyed" << std::endl;
}

void Zombie::announce(void)
{
    // We can do this->name because this is a pointer to the object
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name)
{
    this->name = name;
}