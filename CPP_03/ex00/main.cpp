#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap alice("Alice");

	alice.attack("Bob");
	alice.attack("Chris");
    alice.takeDamage(4);
	alice.attack("Diana");
	alice.attack("Elisa");
	alice.attack("Fred");
	alice.attack("Gemma");
	alice.attack("Henry");
	alice.attack("Isabella");
	alice.attack("Jack");
    alice.beRepaired(2);
	alice.attack("Kevin");
	alice.attack("Laura");
    alice.takeDamage(8);
	alice.attack("Mike");
    return 0;
}