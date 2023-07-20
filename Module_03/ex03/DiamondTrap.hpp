#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	private:
		std::string name;
	public:
		DiamondTrap();
		DiamondTrap(std::string str);
		DiamondTrap(const DiamondTrap &clap);
		DiamondTrap	&operator = (const DiamondTrap &clap);
		~DiamondTrap();

		void	attack(const std::string &target);
		void	whoAmI(void);
		// void			takeDamage(unsigned int amount);
		// void			beRepaired(unsigned int amount);
		// void			setHit(unsigned int n);
		// void			setEnergy(unsigned int n);
		// void			setAtk(unsigned int n);
		// unsigned int	getHit(void);
		// unsigned int	getEnergy(void);
		// unsigned int	getAtk(void);
};

#endif