/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 08:50:49 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/10/09 10:52:01 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	try
	{
		Bureaucrat bur("z", 1);
		AForm *a = new RobotomyRequestForm("home");

		bur.executeForm(*a);
		std::cout << "robo ------------\n";
		for (int i = 1; i < 5; i++)
		{
			std::cout << i << " : ";
			a->execute(bur);
		}
		
		std::cout << "shru ------------\n";
		AForm *b = new ShrubberyCreationForm("home");
		b->execute(bur);
		
		std::cout << "presid ------------\n";
		AForm *c = new PresidentialPardonForm("home");
		c->execute(bur);

		std::cout << "------------\n";
	
		delete (a);
		delete (b);
		delete (c);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
