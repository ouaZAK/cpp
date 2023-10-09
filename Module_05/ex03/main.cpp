/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 08:50:49 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/10/09 12:04:35 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	try
	{
		Bureaucrat b("z", 1);
		Intern a;

		AForm *af = a.makeForm("Shrubbery Creation", "z");
		AForm *bf = a.makeForm("Robotomy Request", "z");
		AForm *cf = a.makeForm("Presidential Pardon", "z");

		std::cout << "shr ------------\n";
		af->execute(b);
		std::cout << "file created\n";

		std::cout << "robo ------------\n";
		for (int i = 1; i < 5; i++)
		{
			std::cout << i << " : ";
			bf->execute(b);
		}

		std::cout << "presid ------------\n";
		if (cf)
			cf->execute(b);
		delete af;
		delete bf;
		delete cf;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}