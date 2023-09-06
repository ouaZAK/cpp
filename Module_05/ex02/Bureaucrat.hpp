/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 08:51:03 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/09/06 08:58:18 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include <iostream>

class AForm;

class Bureaucrat
{
	private:
		const std::string	name;
		int					grade;

	public:
		Bureaucrat();
		Bureaucrat(const Bureaucrat &bur);
		Bureaucrat(std::string name, int grade);
		Bureaucrat &operator = (const Bureaucrat &bur);
		~Bureaucrat();

		const std::string	getName() const;
		int					getGrade() const;
		void				inc();
		void				dec();
		void				signForm(AForm *form) const;
		void				executeForm(AForm const & form);

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

std::ostream &operator << (std::ostream &out, const Bureaucrat &bur);
