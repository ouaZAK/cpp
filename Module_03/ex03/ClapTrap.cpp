/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 18:53:50 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/08/01 19:30:33 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("z")
{
	std::cout << "clap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hp(10), ep(10), ad(0)
{
	std::cout << "clap " << name << " asignement constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &clap)
{
	name = clap.name;
	hp = clap.hp;
	ep = clap.ep;
	ad = clap.ad;
	std::cout << "clap copy constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "clap destructor called" << std::endl;
}

ClapTrap &ClapTrap::operator = (const ClapTrap &clap)
{
	name = clap.name;
	hp = clap.hp;
	ep = clap.ep;
	ad = clap.ad;
	return (*this);
}

void	ClapTrap::attack(const std::string &target)
{
	if (hp && ep)
	{
		std::cout	<< "ClapTrap " << name << " attacks " 
					<< target << ", causing " << ad 
					<< " points of damage!" << std::endl;
		ep--;
	}
	else
		std::cout << "nothing happen" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (hp)
	{
		if (hp - amount < 0)
			hp = 0;
		else
			hp -= amount;
		std::cout	<< "ClapTrap " << name << " took " 
					<< amount << " points of damage!" << std::endl;
	}
	else
		std::cout << "ClapTrap " << name << " is dead" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (hp && ep)
	{
		hp += amount;
		std::cout	<< "ClapTrap " << name << " repaired " 
					<< amount << " of points" << std::endl;
		ep--;
	}
	else
		std::cout << "ClapTrap " << name <<  "cant be repared" << std::endl;
}