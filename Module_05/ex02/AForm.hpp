/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 13:19:08 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/09/04 12:42:54 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"
#include <iostream>

class Bureaucrat;

class AForm
{
	private:
		const std::string	name;
		const int			sign_grade;
		const int			exec_grade;
		bool				signe;

	public:
		AForm();
		AForm(const std::string name, const int sg, const int eg);
		AForm(const AForm &form);
		AForm	&operator = (const AForm &from);
		~AForm();
		
		const std::string	getName(void) const;
		int					getSignGrade(void) const;
		int					getExecGrade(void) const;
		bool				getSigne(void) const;
		void				beSigned(Bureaucrat bur);
		virtual void		execute(Bureaucrat const & executor) const = 0;
		
		class GradeTooHighException
		{
			public:
				const char *what() const throw();
		};

		class GradeTooLowException
		{
			public:
				const char *what() const throw();
		};
};

std::ostream &operator << (std::ostream &out, const AForm &form);