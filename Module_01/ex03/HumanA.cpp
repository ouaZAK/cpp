/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 12:12:01 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/07/31 15:17:18 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &wep) : name(name), a(wep)
{
}

HumanA::~HumanA()
{
}

void	HumanA::attack() const
{
	std::cout << name << " attacks with their " << a.getType() << std::endl;
}

