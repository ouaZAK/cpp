/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 12:12:01 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/09/16 10:31:30 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &wep) : name(name), wep(wep)
{
	this->wep = wep;
}

HumanA::~HumanA()
{
}

void	HumanA::attack() const
{
	if (!wep.getType().empty())
		std::cout << name << " attacks with their " << wep.getType() << std::endl;
	else
		std::cout << name << " attacks with their mistery weapon" << std::endl;
}

