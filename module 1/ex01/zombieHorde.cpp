#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name)
{
    Zombie *some_zombies = new Zombie[N];

    for (int i = 0; i < N; i++)
    {
        some_zombies[i].setName(name);
    }
    return some_zombies;
}