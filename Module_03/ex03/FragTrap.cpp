/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 11:56:43 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/08/03 16:13:17 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "frag default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->name = name;
	hp = 100;
	ad = 30;
	std::cout << "frag " << name << " asignement constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &frag) : ClapTrap(frag)
{
	name = frag.name;
	hp = frag.hp;
	ad = frag.ad;
	std::cout << "frag copy constructor called" << std::endl;
}

FragTrap	&FragTrap::operator = (const FragTrap &frag)
{
	name = frag.name;
	hp = frag.hp;
	ad = frag.ad;
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "frag " << name << "  destructor called" << std::endl;
}

void	FragTrap::attack(const std::string &target)
{
	if (hp && ep)
	{
		std::cout	<< "FragTrap " << name << " attacks " 
					<< target << ", causing " << ad 
					<< " points of damage!" << std::endl;
		ep--;
	}
	else
		std::cout << "nothing happen" << std::endl;
}

void	FragTrap::highFiveGuys(void)
{
	std::cout << "high five from " << name << std::endl;
}
