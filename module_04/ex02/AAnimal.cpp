/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 19:44:43 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/09/28 11:23:14 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal() : type("none")
{
	std::cout << "Animal default constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &animal) : type(animal.type)
{
	std::cout << "Animal copy constructor called" << std::endl;
}

AAnimal	&AAnimal::operator=(const AAnimal &animal)
{
	type = animal.type;
	return (*this);
}

AAnimal::~AAnimal()
{
	std::cout << "Animal destructor called" << std::endl;
}

std::string	AAnimal::getType(void) const
{
	return (type);
}
