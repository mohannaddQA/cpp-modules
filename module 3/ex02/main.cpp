#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
    {
        ScavTrap guard("Scav");
        guard.attack("training dummy");
        guard.guardGate();
    }
    {
        FragTrap robot("Frag");
        robot.attack("training dummy");
        robot.takeDamage(20);
        robot.beRepaired(10);
        robot.highFivesGuys();
    }
    return 0;
}
