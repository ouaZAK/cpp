/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 17:08:01 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/09/18 12:03:37 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() : str("empty")
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &sca)
{
	*this = sca;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &sca)
{
	(void)sca;
	return (*this);	
}

ScalarConverter::~ScalarConverter()
{
}

double	get_double(const std::string &str)
{
	double	x;
	char 	*endPtr;
	
	x = std::strtod(str.c_str(), &endPtr);
	if (endPtr == str)
		throw (std::exception());//error
		// std::cout << "no conversion happened" << std::endl;
	return (x);
}

char	get_char(const std::string &str)
{
	int		y;
	double	x;

	x = get_double(str);
	y = static_cast<int>(x);
	if (y >= 126 || y <= 32)
		throw (std::exception());//overflow or nonprintable
	return (y);
}

void char_conv(const std::string &str)
{
	char c;

	std::cout << "char: ";
	try
	{
		c = get_char(str);
		std::cout << c << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cout << "Non displayable" << std::endl;
	}
}

void	int_conv(const std::string &str)
{
	double	d;
	int		i;
	
	std::cout << "int: ";
	try
	{
		d = get_double(str);
		i = static_cast<int>(d);
		std::cout << i << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;//error
	}
}

void	float_conv(const std::string &str)
{
	double	d;
	float	f;

	std::cout << "float: ";
	try
	{
		d = get_double(str);
		f = static_cast<float>(d);
		std::cout << f ;
		if (str.find('.', 0) == std::string::npos)
			std::cout << ".0";
		std::cout << "f" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;//error
	}
}

void	double_conv(const std::string &str)
{
	double	d;

	std::cout << "double ";
	try
	{
		d = get_double(str);
		std::cout << d;
		if (str.find('.', 0) == std::string::npos)
			std::cout << ".0";
		std::cout << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

void	ScalarConverter::convert(const std::string &str)
{
	char_conv(str);
	int_conv(str);
	float_conv(str);
	double_conv(str);
}
