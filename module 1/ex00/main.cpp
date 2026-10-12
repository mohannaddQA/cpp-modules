#include "Zombie.hpp"

int main()
{
    Zombie *my_zombie = newZombie("Mohannad");

    my_zombie->announce();
    randomChump("Ali");

    delete my_zombie;
}
