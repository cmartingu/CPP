#include "Zombie.hpp"

int main(void)
{
    Zombie  *horde = zombieHorde(9, "Juan");
    for (int i = 0; i < 9; i++)
        horde[i].announce();
    delete [] horde;
}