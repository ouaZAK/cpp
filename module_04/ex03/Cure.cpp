/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 09:58:27 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/08/04 18:44:59 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : cure("none")
{
	std::cout << "Cure default constructor called" << std::endl;
}

Cure::Cure(std::string const &cure) : cure(cure)
{
	std::cout << "Cure custom constructor called" << std::endl;
}

Cure::Cure(const Cure &cure) : cure(cure.cure)
{
	std::cout << "Cure copy constructor called" << std::endl;
}

Cure &Cure::operator = (const Cure &cure)
{
	this->cure = cure.cure;
	return (*this);
}

Cure::~Cure()
{
	std::cout << "Cure destructor called" << std::endl;
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals" << target.getName() << 's wounds *' << std::endl;
}

Cure* Cure::clone() const
{
	Cure *c = new Cure;
	return (c);
}