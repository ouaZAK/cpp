/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 13:19:08 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/09/03 13:51:55 by zouaraqa         ###   ########.fr       */
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
		const std::string	getName(void);
		const int			getSignGrade(void);
		const int			getSignGrade(void);
		bool				getSigne(void);
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