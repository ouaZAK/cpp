/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 16:18:17 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/09/18 16:28:50 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <iomanip>

class ScalarConverter
{
	private:
		std::string str;
	public:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &sca);
		ScalarConverter &operator=(const ScalarConverter &sca);
		~ScalarConverter();
		static void	convert(const std::string &str);

		class Impossible : public std::exception
		{
			const char *what() const throw()
			{
				return ("impossible");
			}	
		};

		class NonDisplayable : public std::exception
		{
			const char *what() const throw()
			{
				return ("Non displayable");
			}	
		};
};