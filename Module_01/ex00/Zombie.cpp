#include "Zombie.hpp"

std::string	Zombie::get_name(void)
{
	return (this->name);
}

void	Zombie::set_name(std::string name)
{
	this->name = name;
}

void	Zombie::annouce(void)
{
	std::cout << get_name() << ": " << "BraiiiiiiinnnzzzZ..."<< std::endl;
}