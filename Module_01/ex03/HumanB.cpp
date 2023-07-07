#include "HumanB.hpp"

void	HumanB::attack()
{
	if (!(this->wepB) || !this->wepB->get_type().compare(""))
		std::cout << this->name << " has no weapon" << std::endl;
	else
		std::cout	<< this->name << " attacks with their " 
					<< this->wepB->get_type() << std::endl;
}

void	HumanB::setWeapon(Weapon &w)
{
	this->wepB = &w;
}
