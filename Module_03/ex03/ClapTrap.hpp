#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string.h>

class ClapTrap
{
	protected:
		std::string		name;
		unsigned int	hit;
		unsigned int	energy;
		unsigned int	atk;

	public:
		ClapTrap();
		ClapTrap(std::string str);
		ClapTrap(const ClapTrap &clap);
		ClapTrap	&operator = (const ClapTrap &clap);
		~ClapTrap();

		void			attack(const std::string &target);
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);
		void			setHit(unsigned int n);
		void			setEnergy(unsigned int n);
		void			setAtk(unsigned int n);
		unsigned int	getHit(void);
		unsigned int	getEnergy(void);
		unsigned int	getAtk(void);
};

#endif