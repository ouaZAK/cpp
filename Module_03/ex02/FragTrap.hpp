#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap();
		FragTrap(std::string str);
		FragTrap(const FragTrap &clap);
		FragTrap	&operator = (const FragTrap &clap);
		~FragTrap();

		void	attack(const std::string &target);
		void	highFivesGuys(void);
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