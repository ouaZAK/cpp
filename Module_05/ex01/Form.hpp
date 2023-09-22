/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 13:19:08 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/09/22 14:53:39 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"
#include <iostream>

class Bureaucrat;

class Form
{
	private:
		const std::string	name;
		const int			sign_grade;
		const int			exec_grade;
		bool				signe;

	public:
		Form();
		Form(const std::string name, const int sg, const int eg);
		Form(const Form &form);
		~Form();
		Form	&operator = (const Form &from);
		
		const std::string	getName(void) const;
		int					getSignGrade(void) const;
		int					getExecGrade(void) const;
		bool				getSigne(void) const;
		void				beSigned(Bureaucrat bur);
		
		class GradeTooHighException : public std::exception
		{
			public:
				const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char *what() const throw();
		};
};

std::ostream &operator << (std::ostream &out, const Form &form);