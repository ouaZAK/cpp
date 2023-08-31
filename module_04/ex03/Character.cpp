/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 10:36:35 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/08/31 14:45:11 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : name("none")
{
	std::cout << "Character default constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		slot[i] = NULL;
		save[i] = NULL;
	}
}

Character::Character(std::string const &name) : name(name)
{
	for (int i = 0; i < 4; i++)
	{
		slot[i] = NULL;
		save[i] = NULL;
	}
	std::cout << "Character custom constructor called" << std::endl;
}

Character::Character(const Character &character) : name(character.name)
{
	*this = character;
	std::cout << "Character assignement constructor called" << std::endl;
}

Character &Character::operator = (const Character &character)
{
	name = character.name;
	for (int i = 0; i < 4; i++)
	{
		if (slot[i])
			delete (slot[i]);
		slot[i] = character.slot[i]->clone();
	}
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
		if (save[i])
			delete(save[i]);
	for (int i = 0; i < 4; i++)
	{
		if (!slot[i])
		{
			slot[i] = m;
			break ;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4 && slot[idx])
	{
		save[idx] = slot[idx];
		slot[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < 4 && slot[idx])
		slot[idx]->use(target);
}