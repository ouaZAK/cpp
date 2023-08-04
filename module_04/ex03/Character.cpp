/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 10:36:35 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/08/04 11:29:43 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character()
{
	for (int i = 0; i < 4; i++)
		slot[i] = NULL;
}

Character::Character(std::string const &character)
{
}

Character::Character(const Character &character)
{
}

Character &Character::operator = (const Character &character)
{
	
}

Character::~Character()
{
}

std::string const &Character::getName() const
{
	return (name);
}

void Character::equip(AMateria* m)
{
	for (int i = 0; i < 3; i++)
	{
		if (!slot[i])
			slot[i] = m;
	}
}

void Character::unequip(int idx)
{
	if (slot[idx])
	{
		save = slot[idx]; //leaks should be here
		slot[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (slot[idx])
		slot[idx]->use(target);
}