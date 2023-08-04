/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 09:49:18 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/08/04 18:43:39 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() : type("none")
{
	std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(std::string const &type) : type(type)
{
	std::cout << "AMateria custom constructor called" << std::endl;
}

AMateria::AMateria(const AMateria &type) : type(type.type)
{
	std::cout << "AMateria copy constructor called" << std::endl;
}

AMateria &AMateria::operator = (const AMateria &type)
{
	this->type = type.type;
	return (*this);
}

AMateria::~AMateria()
{
	std::cout << "AMateria destructor called" << std::endl;
}
