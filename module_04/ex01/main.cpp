/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 08:59:16 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/08/06 09:20:21 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int _main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	const Animal *x[4];
	for (int i = 0; i < 4; i++)
	{
		if (i < (4 / 2))
			x[i] = new Dog();
		else
			x[i] = new Cat();
	}

	for (int i = 0; i < 4; i++)
		delete (x[i]);
	// Cat a,b;
	// a = b;
	// Dog x,y;
	// x = y;
	// delete i;
	// i = j;
	// std::cout << "i = "<< a.getType() << "\n" << "j = "<< b.getType() <<std::endl;

	std::cout << "----------\n";
	// std::cout << "i = "<< i << "\n" << "j = "<< j <<std::endl;
	std::cout << "----------\n";
	
	delete j;//s
	delete i;
	
	return (0);
}

int main()
{
	_main();
	system("leaks poly");
}