#include "Zombie.hpp"

Zombie *newZombie(std::string name)
{
	Zombie *z;

	z = new Zombie;
	z->set_name(name);
	return (z);
}
