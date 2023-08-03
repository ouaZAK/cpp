/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 12:49:52 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/08/03 16:24:56 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap()
{
	name = "z";
	ClapTrap::name = "z_clap_name";
	std::cout << "diam default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string &name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
	ClapTrap::name = name + "_clap_name";
	this->name = name;
	hp = FragTrap::hp;
	ep = ScavTrap::ep;
	ad = FragTrap::ad;
	std::cout << "diam " << name << " asignement constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &diam) : ClapTrap(diam), ScavTrap(diam), FragTrap(diam)
{
	name = diam.name;
	hp = FragTrap::hp;
	ep = ScavTrap::ep;
	ad = FragTrap::ad;
	std::cout << "diam copy constructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator = (const DiamondTrap &diam)
{
	name = diam.name;
	hp = diam.hp;
	ep = diam.ep;
	ad = diam.ad;
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "diam " << name << " destructor called" << std::endl;
}

void	DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void)
{
	std::cout	<< "diam name : " << name 
				<< "\nclap name :" << ClapTrap::name << std::endl;
}