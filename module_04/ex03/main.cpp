/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 10:34:44 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/08/06 16:27:22 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "Character.hpp"

int main()
{
	AMateria *a = new Cure("zak");
	ICharacter *ich = new Character("la");
	Character ch2("b");
	ch2.equip(a);
	ch2.use(0, *ich);
	delete ich;
	delete a;
	// ch2.equip(ch1);
	// IMateriaSource* src = new MateriaSource();
	// src->learnMateria(new Ice());
	// src->learnMateria(new Cure());
	// ICharacter* me = new Character("me");
	// // AMateria* tmp;
	// // // tmp = src->createMateria("ice");
	// // me->equip(tmp);
	// // // tmp = src->createMateria("cure");
	// // me->equip(tmp);
	// ICharacter* bob = new Character("bob");
	// me->use(0, *bob);
	// me->use(1, *bob);
	// delete bob;
	// delete me;
	// delete src;
	return 0;
}