/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 09:56:30 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/08/06 09:24:58 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : ice("none")
{
	std::cout << "Ice default constructor called" << std::endl;
}

Ice::Ice(std::string const &ice) : ice(ice)
{
	std::cout << "Ice custom constructor called" << std::endl;
}

Ice::Ice(const Ice &ice) : ice(ice.ice)
{
	std::cout << "Ice copy constructor called" << std::endl;
}

Ice &Ice::operator = (const Ice &ice)
{
	this->ice = ice.ice;
	return (*this);
}

Ice::~Ice()
{
	std::cout << "Ice destructor called" << std::endl;
}

std::string  const &Ice::getType() const
{
	return (ice);
}

Ice* Ice::clone() const
{
	Ice *i = new Ice;
	return (i);
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}