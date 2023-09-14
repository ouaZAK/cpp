/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 10:15:22 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/09/14 11:54:11 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "def const called" << std::endl;
}

Intern::Intern(const Intern &intern)
{
	*this = intern;
	std::cout << "copy const called" << std::endl;
}

Intern	&Intern::operator = (const Intern &intern)
{
	(void)intern;
	return (*this);
}

Intern::~Intern()
{
	std::cout << "destructor called" << std::endl;
}

AForm	*Intern::makeForm(std::string formName, std::string target)
{
	std::string arr[3] = {"presidential pardon", "Shrubbery Creation", "Robotomy Request"};
	AForm *form[3] = {new PresidentialPardonForm(target), new ShrubberyCreationForm(target), new RobotomyRequestForm(target)};
	for (int i = 0; i < 3; i++)
	{
		if (arr[i] == formName)
		{
			std::cout << "Intern creates " << formName << std::endl;
			for (int y = 0; y < 3; y++)
				if (y != i)
					delete form[y];
			return (form[i]);
		}	
	}
	std::cout << "no matching form" << std::endl;
	return (nullptr);
}
