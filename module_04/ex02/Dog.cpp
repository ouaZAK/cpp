/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 19:43:33 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/08/03 19:44:20 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Dog.hpp"

Dog::Dog()
{
	type = "Dog";
	b = new Brain();
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog &dog) : AAnimal(dog)
{
	type = dog.type;
	b = new Brain(*dog.b);
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog	&Dog::operator=(const Dog &dog)
{
	type = dog.type;
	delete (b);
	b = new Brain(*dog.b);
	return (*this);
}

Dog::~Dog()
{
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
