#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(void) : ClapTrap()
{
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "FragTrap " << _name << " constructed" << std::endl;
}

FragTrap::FragTrap(std::string const &name) : ClapTrap(name)
{
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "FragTrap " << _name << " constructed" << std::endl;
}

FragTrap::FragTrap(FragTrap const &other) : ClapTrap(other)
{
    std::cout << "FragTrap " << _name << " copied" << std::endl;
}

FragTrap &FragTrap::operator=(FragTrap const &other)
{
    ClapTrap::operator=(other);
    return *this;
}

FragTrap::~FragTrap(void)
{
    std::cout << "FragTrap " << _name << " destroyed" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << _name << " High five!" << std::endl;
}
