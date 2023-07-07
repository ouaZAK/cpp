#include "HumanA.hpp"

void	HumanA::attack()
{
	if (!(this->wepA) || this->wepA->get_type() == "")
	{
		std::cout	<< this->name << " attacks with their " 
					<< "weapon" << std::endl;
	}
	else
		std::cout	<< this->name << " attacks with their " 
					<< this->wepA->get_type() << std::endl;
}