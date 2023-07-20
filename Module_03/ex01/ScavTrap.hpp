#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(std::string str);
		ScavTrap(const ScavTrap &clap);
		ScavTrap	&operator = (const ScavTrap &clap);
		~ScavTrap();

		void	attack(const std::string &target);
		void	guardGate(void);
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