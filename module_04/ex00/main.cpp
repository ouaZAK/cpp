/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 08:59:16 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/09/25 11:48:41 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int _main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << "----------" << std::endl;
	std::cout << j->getType() << std::endl;
	std::cout << i->getType() << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	std::cout << "\n###########\n"<< std::endl;

	const WrongAnimal* g = new WrongCat();
	WrongCat ca;

	std::cout << "----------" << std::endl;
	std::cout << g->getType() << std::endl;
	g->makeSound(); //will output silent
	std::cout << "----------" << std::endl;
	std::cout << ca.getType() << std::endl;
	ca.makeSound(); //will output the cat sound!
	std::cout << "----------" << std::endl;

	delete (g);
	delete (i);
	delete (j);
	delete (meta);
	return (0);
}

int main()
{
	_main();
	std::cout << "----------" << std::endl;
	system("leaks -q poly");
	std::cout << "----------" << std::endl;
}
