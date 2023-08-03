/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 08:59:16 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/08/03 18:50:58 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
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
	
	std::cout << "###########"<< std::endl;
	
	const WrongAnimal* g = new WrongCat();
	std::cout << "----------" << std::endl;
	std::cout << g->getType() << std::endl;
	g->makeSound(); //will output the cat sound!

	delete (g);
	delete (i);
	delete (j);
	delete (meta);
	return (0);
}
