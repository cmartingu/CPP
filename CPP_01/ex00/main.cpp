#include "Zombie.hpp"

int main(void)
{
    Zombie  *z = newZombie("Paco");
    z->announce();
    randomChump("Julio");
    z->~Zombie();
}