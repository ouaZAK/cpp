/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 12:26:10 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/09/11 13:49:52 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy Request", 72, 45)
{
	std::cout << "default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy Request", 72, 45), target(target)
{
	std::cout << "custom constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &robo) : AForm("Robotomy Request", 72, 45)
{
	*this = robo;
	std::cout << "copy constructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator = (const RobotomyRequestForm &robo)
{
	target = robo.target;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "destructor called" << std::endl;
}

void	RobotomyRequestForm::executing(void) const
{
	static int i;

	if (i % 2)
		std::cout << "Makes some drilling noises. " << target <<" has been robotomized" << std::endl;
	else
		std::cout << "the robotomy failed." << std::endl;
	i++;
}
