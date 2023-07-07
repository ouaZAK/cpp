#include "Weapon.hpp"

std::string const	&Weapon::get_type()
{
	return (this->type);
}

void	Weapon::setType(std::string str)
{
	this->type = str;
}