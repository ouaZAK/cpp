#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "Default Clap Constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string str) : name(str), hit(10), energy(10), atk(0)
{
	std::cout << "Clap Constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Clap Destructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &clap)
{
	*this = clap;
}

ClapTrap	&ClapTrap::operator = (const ClapTrap &clap)
{
	hit = clap.hit;
	energy = clap.energy;
	atk = clap.atk;
	return (*this);
}

void	ClapTrap::attack(const std::string &target)
{
	if (hit)
	{
		if (energy)
		{
			energy--;
			std::cout	<< "ClapTrap "<< name << " attacks " << target 
						<< ", causing " << atk << " points of damage!" << std::endl;
		}
		else
			std::cout << "no more energy left" << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (hit)
	{
		if (hit < amount)
			hit = 0;
		else
			hit -= amount;
		std::cout	<< "ClapTrap " << name << " took " << amount 
					<< " of damage points!" << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (hit)
	{
		if (energy)
		{
			energy--;
			hit += amount;
			std::cout	<< "ClapTrap " << name << " repaired " 
						<< amount << " of points" << std::endl;
		}
		else
			std::cout << "no more energy left" << std::endl;
	}
}

void	ClapTrap::setHit(unsigned int n)
{
	this->hit = n;
}

void	ClapTrap::setEnergy(unsigned int n)
{
	this->energy = n;
}

void	ClapTrap::setAtk(unsigned int n)
{
	this->atk = n;
}

unsigned int	ClapTrap::getHit(void)
{
	return (this->hit);
}

unsigned int	ClapTrap::getEnergy(void)
{
	return (this->energy);
}

unsigned int	ClapTrap::getAtk(void)
{
	return (this->atk);
}