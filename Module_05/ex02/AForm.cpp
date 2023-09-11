/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 13:19:04 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/09/11 13:51:56 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : name("none"), sign_grade(0), exec_grade(0), signe(false)
{
	std::cout << "default constructor called" << std::endl;
}

AForm::AForm(std::string name, const int sg, const int eg) : name(name), sign_grade(sg), exec_grade(eg)
{
	std::cout << "custom constructor called" << std::endl;
}

AForm::AForm(const AForm &form) : name(form.name), sign_grade(form.sign_grade), exec_grade(form.exec_grade)
{
	std::cout << "copy constructor called" << std::endl;
}

AForm &AForm::operator = (const AForm &form)
{
	signe = form.getSigne();
	return (*this);
}

AForm::~AForm()
{
	std::cout << "destructor called" << std::endl;
}

const std::string	AForm::getName(void) const
{
	return (name);
}

int	AForm::getSignGrade(void) const
{
	return (sign_grade);
}

int	AForm::getExecGrade(void) const
{
	return (exec_grade);
}

bool	AForm::getSigne(void) const
{
	return (signe);
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("GradeTooHigh");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("GradeTooLow");
}

void	AForm::beSigned(Bureaucrat bur)
{
	// std::cout << bur.getGrade() << " " <<sign_grade << std::endl;
	if (bur.getGrade() > sign_grade)
		throw(AForm::GradeTooLowException());
	signe = true;
}

std::ostream &operator << (std::ostream &out, const AForm &form)
{
	out << "name : " << form.getName() << "\n"
		<< "signed grade : " << form.getSignGrade() << "\n"
		<< "executed : " << form.getExecGrade() << "\n"
		<< "signed : " << form.getSigne() << std::endl;
	return (out);
}

void	AForm::execute(Bureaucrat const & executor) const
{
	if (!getSigne() && executor.getGrade() > getExecGrade())
		throw (AForm::GradeTooLowException());
	executing();
}
