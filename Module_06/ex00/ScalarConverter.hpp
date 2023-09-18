/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 16:18:17 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/09/18 08:10:17 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

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
};