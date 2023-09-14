/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 08:50:49 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/09/14 11:52:08 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int _main()
{
	try
	{
		Bureaucrat b("z", 1);
		Intern a;
		
		// AForm *a = new RobotomyRequestForm("home");
		AForm *af = a.makeForm("Shrubbery Creation", "z");
		af->execute(b);
		// af->execute(b);
		// a->execute(b);
		// b.executeForm(*a);
		delete af;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
int main()
{
	_main();
	system("leaks -q Form");
}
