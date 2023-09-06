/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 12:24:34 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/09/06 13:14:28 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery Creation", 145, 137)
{
	std::cout << "default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery Creation", 145, 137), target(target)
{
	std::cout << "custom constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &shr) : AForm("Shrubbery Creation", 145, 137)
{
	*this = shr;
	std::cout << "copy constructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator = (const ShrubberyCreationForm &shr)
{
	target = shr.target;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "destructor called" << std::endl;
}

void	executing1(const std::string target)
{
	std::cout <<target << " tree\n";
}

void	ShrubberyCreationForm::executing(void) const
{
	std::ofstream	outF(target + "_shrubbery");
	if (outF.fail())
		throw (std::exception());
	for (int i = 0; i < 5; i++)
		for(int j = 0; i < j )
    #
   ###
  #####
 #######
}
