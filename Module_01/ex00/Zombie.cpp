/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 19:57:00 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/07/31 12:58:04 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name) : name(name)
{
}

Zombie::~Zombie(){}

std::string	Zombie::get_name(void)
{
	return (this->name);
}

void	Zombie::set_name(std::string name)
{
	this->name = name;
}

void	Zombie::annouce(void)
{
	std::cout << get_name() << ": " << "BraiiiiiiinnnzzzZ..."<< std::endl;
}