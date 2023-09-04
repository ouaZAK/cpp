/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 13:19:04 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/09/04 12:11:44 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : name("none"), sign_grade(0), exec_grade(0), signe(false)
{
	std::cout << "default constructor called" << std::endl;
}

Form::Form(std::string name, const int sg, const int eg) : name(name), sign_grade(sg), exec_grade(eg)
{
	std::cout << "custom constructor called" << std::endl;
}

Form::Form(const Form &form) : name(form.name), sign_grade(form.sign_grade), exec_grade(form.exec_grade)
{
	std::cout << "copy constructor called" << std::endl;
}

Form &Form::operator = (const Form &form)
{
	signe = form.getSigne();
	return (*this);
}

Form::~Form()
{
	std::cout << "destructor called" << std::endl;
}

const std::string	Form::getName(void) const
{
	return (name);
}

int	Form::getSignGrade(void) const
{
	return (sign_grade);
}

int	Form::getExecGrade(void) const
{
	return (exec_grade);
}

bool	Form::getSigne(void) const
{
	return (signe);
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("GradeTooHigh");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("GradeTooLow");
}

void	Form::beSigned(Bureaucrat bur)
{
	if (bur.getGrade() > sign_grade)
		throw(Form::GradeTooLowException());
	signe = true;
}

std::ostream &operator << (std::ostream &out, const Form &form)
{
	out << "name : " << form.getName() << "\n"
		<< "signed grade : " << form.getSignGrade() << "\n"
		<< "executed : " << form.getExecGrade() << "\n"
		<< "signed : " << form.getSigne() << std::endl;
	return (out);
}