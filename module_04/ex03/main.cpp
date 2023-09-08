/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 10:34:44 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/09/08 11:07:49 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int _main()
{
	AMateria *a = NULL;
	AMateria *b = new Cure("b");
	// AMateria *c = NULL;
	Character c1;
	c1.equip(a);
	Character c2;
	// c2.equip(b);
	// c2 = c1;
	// c1.unequip(0);
	// c1.unequip(1);
	// c1.equip(a);
	// c1 = c2;
	// c1.equip(c);
	c1.use(0, c2);
	delete (a);
	delete (b);
	// IMateriaSource* src = new MateriaSource();
	// src->learnMateria(new Ice());
	// src->learnMateria(new Cure());
	// ICharacter* me = new Character("me");
	// AMateria* tmp;
	// tmp = src->createMateria("cure");
	// me->equip(tmp);
	// tmp = src->createMateria("ice");
	// me->equip(tmp);
	// ICharacter* bob = new Character("bob");
	// me->use(0, *bob);
	// me->use(1, *bob);
	// delete bob;
	// delete me;
	// delete src;
	return 0;
}
int main()
{
	_main();
	system("leaks poly");
}