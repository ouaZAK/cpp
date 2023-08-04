/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 10:36:35 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/08/04 18:47:07 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : name("none")
{
	std::cout << "Character default constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		slot[i] = NULL;
}

Character::Character(std::string const &name) : name(name)
{
	for (int i = 0; i < 4; i++)
		slot[i] = NULL;
	std::cout << "Character custom constructor called" << std::endl;
}

Character::Character(const Character &character) : name(character.name)
{
	for (int i = 0; i < 4; i++)
		slot[i] = character.slot[i]->clone();
	std::cout << "Character assignement constructor called" << std::endl;
}

Character &Character::operator = (const Character &character)
{
	name = character.name;
	return (*this);
}

Character::~Character()
{
	std::cout << "Character destructor called" << std::endl;
}

std::string const &Character::getName() const
{
	return (name);
}

void Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (!slot[i])
			slot[i] = m;
	}
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4 && slot[idx])
	{
		save = slot[idx]; //leaks should be here
		slot[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < 4 && slot[idx])
		slot[idx]->use(target);
}