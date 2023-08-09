/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 11:44:24 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/08/09 15:00:01 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() : name("none")
{
}

Zombie::Zombie(std::string name) : name(name)
{
}

Zombie::~Zombie(){}

void	Zombie::annouce(void)
{
	std::cout << name << ": " << "BraiiiiiiinnnzzzZ..."<< std::endl;
}