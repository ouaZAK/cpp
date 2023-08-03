/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 19:57:33 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/08/03 16:12:35 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "default scav constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->name = name;
	ep = 50;
	std::cout << "scav " << name << " asignement constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &scav) : ClapTrap(scav)
{
	name = scav.name;
	ep = scav.ep;
	std::cout << "scav copy constructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "scav " << name << "  destructor called" << std::endl;
}

ScavTrap &ScavTrap::operator = (const ScavTrap &scav)
{
	name = scav.name;
	ep = scav.ep;
	return (*this);
}

void	ScavTrap::attack(const std::string &target)
{
	if (hp && ep)
	{
		std::cout	<< "ScavTrap " << name << " attacks " 
					<< target << ", causing " << ad 
					<< " points of damage!" << std::endl;
		ep--;
	}
	else
		std::cout << "nothing happen" << std::endl;
}

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap is now in Gate keeper mode" << std::endl;
}
