/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 09:56:30 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/08/07 11:02:48 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice"), ice("ice")
{
	std::cout << "Ice default constructor called" << std::endl;
}

Ice::Ice(std::string const &ice) : AMateria(ice), ice(ice)
{
	std::cout << "Ice custom constructor called" << std::endl;
}

Ice::Ice(const Ice &ice) : AMateria(ice), ice(ice.ice)
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
	Ice *i = new Ice(*this);
	return (i);
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}