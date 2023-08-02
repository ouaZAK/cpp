/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 12:12:06 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/07/31 15:58:13 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name)
{
}

HumanB::~HumanB()
{
}

void	HumanB::attack() const
{
	std::cout << name << " attacks with their " << b->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &wep) //&wep ref hold value of obj passed in arg
{
	b = &wep; //pointer hold addres of wep
}