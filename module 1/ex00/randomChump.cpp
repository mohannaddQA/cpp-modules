#include "Zombie.hpp"

void randomChump(std::string name)
{
    // This zombie is only needed in this function, so stack allocation is sufficient.
    Zombie my_zombie = Zombie(name);
    my_zombie.announce();
}
