/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 16:10:05 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/08/06 09:56:51 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"


MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		slot[i] = NULL;
	std::cout << "MateriaSource default constructor called" << std::endl;
}

// MateriaSource::MateriaSource(std::string const &type)
// {
// 	for (int i = 0; i < 4; i++)
// 		slot[i] = NULL;
// 	std::cout << "MateriaSource custom constructor called" << std::endl;
// }

MateriaSource::MateriaSource(const MateriaSource &type)
{
	*this = type;
	std::cout << "MateriaSource copy constructor called" << std::endl;
}

MateriaSource &MateriaSource::operator = (const MateriaSource &type)
{
	for (int i = 0; i < 4; i++)
	{
		delete (slot[i]);
		slot[i] = type.slot[i]->clone();
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
		delete (slot[i]);
	std::cout << "MateriaSource destructor called" << std::endl;
}

void MateriaSource::learnMateria(AMateria*)
{
	
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	
}