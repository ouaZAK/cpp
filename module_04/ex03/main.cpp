/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 10:34:44 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/09/11 09:50:32 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

// int _main()
// {
// 	//######## swl taib #######
// 	AMateria *a = new Cure;
// 	AMateria *b = new Cure;
// 	// AMateria *c = NULL;
// 	Character c1;
// 	c1.equip(a);
// 	Character c2;
// 	// c2.equip(b);
// 	// c2 = c1;
// 	// c1.unequip(0);
// 	// c1.unequip(1);
// 	// c1.equip(a);
// 	// c1 = c2;
// 	// c1.equip(c);
// 	c1.use(0, c2);
// 	delete (a);
// 	delete (b);

// 	// IMateriaSource* src = new MateriaSource();
// 	// src->learnMateria(new Ice());
// 	// src->learnMateria(new Cure());
// 	// ICharacter* me = new Character("me");
// 	// AMateria* tmp;
// 	// tmp = src->createMateria("cure");
// 	// me->equip(tmp);
// 	// tmp = src->createMateria("ice");
// 	// me->equip(tmp);
// 	// ICharacter* bob = new Character("bob");
// 	// me->use(0, *bob);
// 	// me->use(1, *bob);
// 	// delete bob;
// 	// delete me;
// 	// delete src;
// 	return 0;
// }

void	test1()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	
	ICharacter* me = new Character("me");
	
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;	
}

void	test2()
{
	Character *c = new Character;
	Character *c2 = new Character;
	Ice *ice = new Ice;
	c->equip(ice);
	c->equip(ice);
	c->equip(ice);
	c->equip(ice);
	c->equip(new Ice);
	c->equip(new Ice);
	c->equip(new Ice);
	c->equip(ice);
	c->unequip(0);
	c->unequip(1);
	c->unequip(2);
	c->unequip(3);
	c->unequip(4);
	c->unequip(5);
	*c = *c2;
	delete c;
	delete c2;
}

void	test3()
{
	Character c;
	Character c2(c);
	c2.equip(new Ice);
	c2 = c;
}

void	test4()
{
	Character *c = new Character();
	Cure *cure = new Cure();

	c->equip(cure);
	c->unequip(0);

	delete c;
}

void	test5()
{
	AMateria *a = NULL;
	Character *c = new Character;

	c->equip(a);
	c->equip(a);
	c->equip(a);
	c->equip(a);
	c->unequip(0);
	c->unequip(1);
	c->unequip(2);
	c->unequip(3);
	c->unequip(4);
	c->equip(a);
	delete c;
}

void	test6()
{
	AMateria *a = new Ice;
	Character *c = new Character;

	c->equip(a);
	c->unequip(0);
	c->equip(a);
	c->unequip(1);
	c->equip(a);
	c->unequip(2);
	c->equip(a);
	c->unequip(3);
	c->unequip(4);
	c->equip(a);
	delete c;
	delete a;
}

void	test7()
{
	Character a("a");
	a.equip(new Cure());
	a.equip(new Ice());
	a.equip(new Cure());
	a.equip(new Ice());
	
	a.use(0, a);
	a.use(1, a);
	a.use(2, a);
	a.use(3, a);
	
	Character b("b");

	b = a;

	b.use(0, b);
	b.use(1, b);
	b.use(2, b);
	b.use(3, b);
}

void test8()
{
	Character a("a");
	
	a.equip(new Cure());
	a.equip(new Ice());
	a.equip(new Cure());
	a.equip(new Ice());
	
	a.use(0, a);
	a.use(1, a);
	a.use(2, a);
	a.use(3, a);
	
	Character b("b");
	b.equip(new Cure());
	b.equip(new Ice());

	a = b;

	b.use(0, b);
	b.use(1, b);
}

void	test9()
{
    ICharacter *i = new Character("bob");
    
    i->equip(new Cure());
    i->equip(new Ice());
    i->equip(new Cure());
    i->equip(new Ice());
    
    i->unequip(1);
    i->use(1, *i);
    
    i->unequip(0);
	delete i;
}

void	test10()
{
	Character a("a");
	a.equip(new Cure());
	a.equip(new Ice());
	a.equip(new Cure());
	a.equip(new Ice());
	
	a.use(0, a);
	a.use(1, a);
	a.use(2, a);
	a.use(3, a);
	
	Character b("b");

	b = a;

	b.use(0, b);
	b.use(1, b);
	b.use(2, b);
	b.use(3, b);
}

int _main()
{
	std::cout << "--------- test 1 ----------" << std::endl;
	test1();
	std::cout << "--------- test 2 ----------" << std::endl;
	test2();
	std::cout << "--------- test 3 ----------" << std::endl;
	test3();
	std::cout << "--------- test 4 ----------" << std::endl;
	test4();
	std::cout << "--------- test 5 ----------" << std::endl;
	test5();
	std::cout << "--------- test 6 ----------" << std::endl;
	test6();
	std::cout << "--------- test 7 ----------" << std::endl;
	test7();
	std::cout << "--------- test 8 ----------" << std::endl;
	test8();
	std::cout << "--------- test 9 ----------" << std::endl;
	test9();
	std::cout << "--------- test 10 ----------" << std::endl;
	test10();
	std::cout << "--------- test LEAKS ----------" << std::endl;
	return (0);
}
int main()
{
	_main();
	system("leaks -q poly");
}