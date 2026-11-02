#include "ScavTrap.hpp"

int main(void)
{
    ScavTrap robot("Scav");
    robot.attack("training dummy");
    robot.takeDamage(20);
    robot.beRepaired(10);
    robot.guardGate();
    return 0;
}
