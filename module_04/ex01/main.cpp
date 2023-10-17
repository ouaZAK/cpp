/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 08:59:16 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/10/12 13:44:12 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int _main()
{
	// const Animal *x[4];
	
	// for (int i = 0; i < 4; i++)
	// {
	// 	if (i < (4 / 2))
	// 		x[i] = new Dog();
	// 	else
	// 		x[i] = new Cat();
	// }
	
	// std::cout << "----------\n";
	// for (int i = 0; i < 4; i++)
	// 	x[i]->makeSound();
	// std::cout << "----------\n";
	
	// for (int i = 0; i < 4; i++)
	// 	delete (x[i]);

	Animal *a = new Cat;
	a->makeSound();
	delete a;
	// Cat a;
	// Cat b;
	// std::cout << "i = "<< b->getType() 
	// 		<< "\n" 
	// 		<< "j = "<< b->getType() <<std::endl;

	// std::cout << "----------\n";
	// b->makeSound();
	// std::cout << "----------\n";
	
	// delete b;
	return (0);
}

int main()
{
	_main();
	std::cout << "----------\n";
	system("leaks -q poly");
	std::cout << "----------\n";
}