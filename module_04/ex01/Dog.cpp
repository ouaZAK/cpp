/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 19:43:33 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/09/25 12:23:07 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Dog.hpp"

Dog::Dog()
{
	type = "Dog";
	b = new Brain();
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog &dog) : Animal(dog)
{
	*this = dog;
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog	&Dog::operator=(const Dog &dog)
{
	type = dog.type;
	if (b)
		delete (b);
	b = new Brain(*dog.b);
	return (*this);
}

Dog::~Dog()
{
	if (b)
		delete (b);
	std::cout << "Dog destructor called" << std::endl;
}

void	Dog::makeSound(void) const
{
	std::cout << type << " say woof" << std::endl;
}

std::string	Dog::getType(void) const
{
	return (type);
}
