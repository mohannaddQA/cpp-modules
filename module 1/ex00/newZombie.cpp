#include "Zombie.hpp"

Zombie *newZombie(std::string name)
{
    // Since we will return an address, we must not return an adress to a stack location
    // The object must be in the heap
    Zombie *my_zombie = new Zombie(name);
    return my_zombie;
}
