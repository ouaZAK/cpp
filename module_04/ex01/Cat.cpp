/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 19:43:30 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/09/25 12:23:24 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	type = "Cat";
	b = new Brain();
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat &cat) : Animal(cat)
{
	*this = cat;
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat	&Cat::operator=(const Cat &cat)
{
	type = cat.type;
	if (b)
		delete (b);
	b = new Brain(*cat.b);//dereference the pointer *b in cat so the Brain &brain = *cat.b
	return (*this);
}

Cat::~Cat()
{
	if (b)
		delete (b);
	std::cout << "Cat destructor called" << std::endl;
}

void	Cat::makeSound(void) const
{
	std::cout << type << " say meaw" << std::endl;
}

std::string	Cat::getType(void) const
{
	return (type);
}
