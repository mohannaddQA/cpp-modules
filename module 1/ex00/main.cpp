#include "Zombie.hpp"

Zombie *newZombie(std::string name);
void randomChump(std::string name);

int main()
{
    Zombie *my_zombie = newZombie("Mohannad");
    randomChump("Ali");

    delete my_zombie;
}
