# include "HumanB.hpp"

HumanB::HumanB(std::string name): weapon(NULL)
{
    this->name = name;
}

HumanB::~HumanB(void)
{
    std::cout <<"HumanB " << this->name << " destroyed" << std::endl;
}

void    HumanB::setWeapon(Weapon &w)
{
    this->weapon = &w;
}

void    HumanB::attack(void)
{
    std::cout << this->name << " attacks with their " << (*this->weapon).getType() << std::endl;
}