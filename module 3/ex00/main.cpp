#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap robot("CL4P-TP");
    robot.attack("training dummy");
    robot.takeDamage(3);
    robot.beRepaired(2);

    robot.takeDamage(100);
    robot.attack("training dummy");
    robot.beRepaired(1);
    return 0;
}
