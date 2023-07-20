#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
	std::cout << "Default Diam Constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string str) : ScavTrap(str), FragTrap(str)
{
	ScavTrap::name = str + "_clap_name";
	name = str;
	FragTrap::hit = FragTrap::hit;
	ScavTrap::energy = ScavTrap::energy;
	FragTrap::atk = FragTrap::atk;
	// ScavTrap::attack(const std::string &target);
	std::cout << "Diam Constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "Diam Destructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &diam) : ScavTrap(diam), FragTrap(diam)
{
	std::cout << "Diam copy constructror called" << std::endl;
	*this = diam;
}

DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &diam)
{
	name = diam.name;
	FragTrap::hit = FragTrap::hit;
	ScavTrap::energy = ScavTrap::energy;
	FragTrap::atk = FragTrap::atk;
	return (*this);
}

void	DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "DiamondTrap " << " i am " << name << std::endl;
}