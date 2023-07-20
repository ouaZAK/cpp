#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << "Default Scav Constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string str)
{
	name = str;
	hit = 100;
	energy = 50;
	atk = 20;
	std::cout << "Scav Constructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "Scav Destructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &scav) : ClapTrap(scav)
{
	std::cout << "Scav copy constructror called" << std::endl;
	*this = scav;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &scav)
{
	name = scav.name;
	hit = scav.hit;
	energy = scav.energy;
	atk = scav.atk;
	return (*this);
}

void	ScavTrap::attack(const std::string &target)
{
	if (hit)
	{
		if (energy)
		{
			std::cout	<< "ScavTrap "<< name << " attacks " << target
						<< " causing " << atk << " points of damage!"<< std::endl;
			energy--;
		}
		else
			std::cout << "no more energy left" << std::endl;
	}
}

void	ScavTrap::guardGate()
{
	std::cout << "Scavtrap " << name << " is now in Gate Keeper mode" << std::endl;
}