/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 09:58:27 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/08/04 11:10:05 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure()
{
}

Cure::Cure(std::string const &cure)
{
}

Cure::Cure(const Cure &cure)
{
}

Cure &Cure::operator = (const Cure &cure)
{
	
}

Cure::~Cure()
{
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals" << target.getName() << 's wounds *' << std::endl;
}
