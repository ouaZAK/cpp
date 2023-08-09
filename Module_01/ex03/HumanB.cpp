/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 12:12:06 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/08/09 16:11:26 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) :wep(NULL), name(name)
{
}

HumanB::~HumanB()
{
}

void	HumanB::attack() const
{
	if (wep)
	{
		if (!wep->getType().empty())
			std::cout << name << " attacks with their " << wep->getType() << std::endl;
		else
			std::cout << name << " attacks with NO weapon!" << std::endl;
	}
}

void	HumanB::setWeapon(Weapon &wep)
{
	this->wep = &wep;
}