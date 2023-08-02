/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 19:57:33 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/08/01 19:46:18 by zouaraqa         ###   ########.fr       */
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
	hp = 100;
	ep = 50;
	ad = 20;
	std::cout << "scav asignement constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &scav) : ClapTrap(scav)
{
	name = scav.name;
	hp = scav.hp;
	ep = scav.ep;
	ad = scav.ad;
	std::cout << "scav copy constructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "scav destructor called" << std::endl;
}

ScavTrap &ScavTrap::operator = (const ScavTrap &scav)
{
	name = scav.name;
	hp = scav.hp;
	ep = scav.ep;
	ad = scav.ad;
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
