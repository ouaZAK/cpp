#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << "Default frag Constructor called" << std::endl;
}

FragTrap::FragTrap(std::string str)
{
	name = str;
	hit = 100;
	energy = 100;
	atk = 30;
	std::cout << "frag Constructor called" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "frag Destructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &scav) : ClapTrap(scav)
{
	std::cout << "frag copy constructror called" << std::endl;
	*this = scav;
}

FragTrap	&FragTrap::operator=(const FragTrap &scav)
{
	name = scav.name;
	hit = scav.hit;
	energy = scav.energy;
	atk = scav.atk;
	return (*this);
}

void	FragTrap::attack(const std::string &target)
{
	if (hit)
	{
		if (energy)
		{
			std::cout	<< "FragTrap "<< name << " attacks " << target
						<< " causing " << atk << " points of damage!"<< std::endl;
			energy--;
		}
		else
			std::cout << "no more energy left" << std::endl;
	}
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FrgTrap " << name << " say high five!" << std::endl;
}