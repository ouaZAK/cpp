/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 08:59:16 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/09/28 11:19:01 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	// std::cout << "-------------------\n";
	AAnimal *a = new Dog;
	// AAnimal *b = new Dog;
	AAnimal *c = new Dog;
	// a = b;
	*a = *c;
	delete	a;
	// delete	b;
	delete	c;
	system("leaks -q poly");
	// std::cout << "-------------------\n";
	// Cat s;
	// std::cout << "-------------------\n";
	// a->makeSound();
	// s.makeSound();
	// std::cout << "-------------------\n";
	// std::cout << a->getType() <<"\n";
	// std::cout << s.getType() <<"\n";
	// std::cout << "-------------------\n";
	// delete a;
	// std::cout << "-------------------\n";
	return (0);
}
