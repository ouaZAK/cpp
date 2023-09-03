/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 13:19:08 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/09/03 15:02:45 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

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
		Form	&operator = (const Form &from);
		const std::string	getName(void) const;
		const int			getSignGrade(void) const;
		const int			getExecGrade(void) const;
		bool				getSigne(void) const;
		
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

std::ostream &operator << (std::ostream &out, const Form &form);