/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 17:08:01 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/09/19 16:13:13 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cctype>
ScalarConverter::ScalarConverter()
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

int	repeated_char(const std::string &str, char c)
{
	size_t	pos;
	int		count;

	count = 0;
	pos = str.find(c, 0);
	while (pos != std::string::npos)
	{
		count++;
		if (c != 'f' && !str[pos + 1])
			throw (ScalarConverter::Impossible());
		pos = str.find(c, pos + 1);
	}
	return (count);
}

void	check_invalid(const std::string &str, char c)
{
	int count;

	count = repeated_char(str, c);
	if (count != 1 && count != 0)
		throw ScalarConverter::Impossible();

	count = repeated_char(str, 'f');
	if (count != 1 && count != 0)
		throw ScalarConverter::Impossible();

	count = repeated_char(str, '-');
	count += repeated_char(str, '+');
	if (count != 1 && count != 0)
		throw ScalarConverter::Impossible();
}

void	check_digit(const std::string &str)
{
	for (std::string::const_iterator i = str.begin(); i != str.end(); i++)
		if (*i != '.' && *i != '+' && *i != '-' && *i != 'f')
			if (!std::isdigit(*i))
				throw (ScalarConverter::Impossible());
}

bool	check_inf(const std::string &str)
{
	if (str == "-inff" || str == "+inff" || str == "inff" || str == "inf" || str == "-inf" || str == "+inf")
		return (true);
	return (false);
}

int	is_char(const std::string &str)
{
	int		y;

	if ((str.length() == 1 && !std::isdigit(str[0])) || !str.length())//!strlenghth for "" to print '\0'
	{
		y = static_cast<int>(str[0]);
		return (y);
	}
	return (-1);
}

double	get_double(const std::string &str)
{
	double	x;
	char 	*endPtr;

	x = is_char(str);
	if (x != -1)
		return (x);
	check_digit(str);
	check_invalid(str, '.');
	x = std::strtod(str.c_str(), &endPtr);
	if (endPtr == str)
		throw (ScalarConverter::Impossible());
	return (x);
}

char	get_char(const std::string &str)
{
	int		y;
	double	x;

	x = get_double(str);
	y = static_cast<int>(x);
	if (y >= 126 || y <= 32)
		throw (ScalarConverter::NonDisplayable());
	return (y);
}

void char_conv(const std::string &str)
{
	char c;

	std::cout << "char: ";
	try
	{
		if (check_inf(str))
			throw (ScalarConverter::Impossible());
		c = get_char(str);
		std::cout << "\'" << c << "\'" <<  std::endl;
	}
	catch(const std::exception &e)
	{
		std::cout <<e.what() << std::endl;
	}
}

void	int_conv(const std::string &str)
{
	double	d;
	int		i;

	std::cout << "int: ";
	try
	{
		if (check_inf(str))
			throw (ScalarConverter::Impossible());
		d = get_double(str);
		if (d > INT_MAX || d < INT_MIN)
			throw (ScalarConverter::Impossible());
		i = static_cast<int>(d);
		std::cout << i << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

void	float_conv(const std::string &str)
{
	double	d;
	float	f;

	std::cout << "float: ";
	if (check_inf(str))
	{
		std::cout << str <<std::endl;
		return ;
	}
	try
	{
		d = get_double(str);
		f = static_cast<float>(d);
		if (str.find('.', 0) == std::string::npos)
			std::cout << std::fixed << std::setprecision(1);
		else if (str.find('.', 0) != std::string::npos && str.find('f', 0) != std::string::npos)
			std::cout << std::fixed << std::setprecision(str.length() - str.find('.', 0) - 2);
		else
			std::cout << std::fixed << std::setprecision(str.length() - str.find('.', 0) - 1);
		std::cout << f ;
		std::cout << "f" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "nanf " << std::endl;
	}
}

void	double_conv(const std::string &str)
{
	double	d;

	std::cout << "double ";
	if (check_inf(str))
	{
		std::cout << str <<std::endl;
		return ;
	}
	try
	{
		d = get_double(str);
		if (str.find('.', 0) == std::string::npos)
			std::cout << std::fixed << std::setprecision(1);
		else if (str.find('.', 0) != std::string::npos && str.find('f', 0) != std::string::npos)
			std::cout << std::fixed << std::setprecision(str.length() - str.find('.', 0) - 2);
		else
			std::cout << std::fixed << std::setprecision(str.length() - str.find('.', 0) - 1);
		std::cout << d;
		std::cout << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "nan" << std::endl;
	}
}

void	ScalarConverter::convert(const std::string &str)
{
	
	char_conv(str);
	int_conv(str);
	float_conv(str);
	double_conv(str);
}
