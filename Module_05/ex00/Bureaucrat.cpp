/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 08:58:05 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/09/04 12:15:33 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("none"), grade(0)
{
	std::cout << "default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade)
{
	if (grade < 1)
		throw (Bureaucrat::GradeTooHighException());
	else if (grade > 150)
		throw (Bureaucrat::GradeTooLowException());
	std::cout << "custom constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &bur)
{
	*this = bur;
	std::cout << "copy constructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator = (const Bureaucrat &bur)
{
	grade = bur.getGrade();
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "destructor called" << std::endl;
}

const std::string	Bureaucrat::getName(void) const
{
	return (name);
}

int	Bureaucrat::getGrade(void) const
{
	return (grade);
}

void	Bureaucrat::inc(void)
{
	if (grade - 1 < 1)
		throw (GradeTooHighException());
	grade--;
}

void	Bureaucrat::dec(void)
{
	if (grade + 1 > 150)
		throw (GradeTooLowException());
	grade++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("GradeTooHigh");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("GradeTooLow");
}

std::ostream &operator << (std::ostream &out, const Bureaucrat &bur)
{
	out << bur.getName() << ", bureaucrat grade " << bur.getGrade() << "." << std::endl;
	return (out);
}