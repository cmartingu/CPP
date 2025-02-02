#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &w): weapon(w)
{
    this->name = name;
}

HumanA::~HumanA(void)
{
    std::cout << "HumanA " << this->name << " destroyed" << std::endl;
}

void    HumanA::attack(void)
{
    std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
}