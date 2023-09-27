/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 10:34:44 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/09/25 13:11:36 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int _main()
{
	//######## swl taib #######
	// AMateria *a = new Cure();
	// AMateria *b = new Cure;
	// IMateriaSource *src = new MateriaSource();
	// std::cout << src << std::endl;
	// src->learnMateria(new Cure());
	// AMateria *tmp;
	// tmp = src->createMateria("cure");
	// // std::cout << tmp->getType() << std::endl;
	// // AMateria *c = NULL;
	// ICharacter *c1 = new Character("z");
	// c1->equip(tmp);
	// c1->use(1, *c1);
	// delete c1;
	// // delete tmp;
	// delete src;
	// Character c2;
	// c2.equip(b);
	// std::cout << "jj\n";
	// b->use(c2);
	// c1.equip(a);
	// c2.equip(b);
	// c2 = c1;
	// c1.unequip(0);
	// c1.unequip(1);
	// c1.equip(a);
	// c1 = c2;
	// c1.equip(c);
	// c1.use(0, c2);
	// delete (a);
	// delete (m);
	
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	std::cout << "---------  --------" << std::endl;
	me->use(0, *bob);
	me->use(1, *bob);
	std::cout << "---------  --------" << std::endl;
	delete bob;
	delete me;
	delete src;
	return 0;
}

int main()
{
	_main();
	std::cout << "--------- LEAKS --------" << std::endl;
	system("leaks -q poly");
}