/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 08:59:16 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/09/25 12:31:07 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "-------------------\n";
	AAnimal *a = new Dog;
	std::cout << "-------------------\n";
	Cat s;
	std::cout << "-------------------\n";
	a->makeSound();
	s.makeSound();
	std::cout << "-------------------\n";
	std::cout << a->getType() <<"\n";
	std::cout << s.getType() <<"\n";
	std::cout << "-------------------\n";
	delete a;
	std::cout << "-------------------\n";
	return (0);
}
