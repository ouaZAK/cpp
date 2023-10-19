/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 09:11:28 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/10/19 11:05:04 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(char *av)
{
	av1 = static_cast<std::string>(av);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &bitc)
{
	if (this != &bitc)
		*this = bitc;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &bitc)
{
	map = bitc.map;
	line = bitc.line;
	tmp = bitc.tmp;
	av1 = bitc.av1;
	d = bitc.d;
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
}

void	throwing(std::string str)
{
	throw (str);
}

void	checkValue(std::string &str)
{
	int count;
	int qCount;

	count = 0;
	qCount = 0;
	for (std::string::iterator it = str.begin(); it != str.end(); it++)
	{
		if (*it != '.' && *it != '-' && *it != '+')
			if (!std::isdigit(*it))
				throwing("Error: not a number");
		if (*it == '.')
		{
			if ((!std::isdigit(*(it - 1)) && !std::isdigit(*(it + 1))) || (it + 1) == str.end() || it == str.begin())
				throwing("Error: not a number");
			count++;
		}
		if (*it == '-' || *it == '+')
		{
			qCount++;
			if (it != str.begin())
				throwing("Error: not a number");
			else if (it == str.begin() && *it != '+')
				throwing("Error: not a positive number.");
		}
		if (count > 1 || qCount > 1)
			throwing("Error: not a number");
	}

	double d = std::strtod(str.c_str(), NULL);
	if (d > 1000)
		throwing("Error: too large a numbe.");
}

bool	checkDigit(std::string &str, int n)
{
	for (std::string::iterator it = str.begin(); it != str.end(); it++)
		if (*it != '-')
			if (!std::isdigit(*it))
				return (true);

	double d = std::strtod(str.c_str(), NULL);
	if (n == 2)
	{
		if (d > 12 || d < 1)
			return (true);
	}
	else if (n == 3)
	{
		if (d < 1 || d > 31)
			return (true);
	}
	else if (n == 1)
	{
		if (d < 1)
			return (true);
	}
	return (false);
}

void	checkDate(std::string &str)
{
	size_t	n = 0;
	int		count = 0;

	while (1)
	{
		n = str.find('-', n + 1);
		if (n == std::string::npos)
		{
			if (count != 2)
				throwing("Error: bad input => " + str.substr(0, str.size()));
			else
				break ;
		}
		count++;
	}
	size_t	first_of = str.find_first_of('-', 0);
	size_t	second_of = str.find('-', first_of + 1) - 1 - first_of;
	size_t	third_of = str.find_last_of('-', str.size()) + 1;

	std::string str1 = str.substr(0, first_of);
	std::string str2 = str.substr(first_of + 1, second_of);
	std::string str3 = str.substr(third_of, str.size() - third_of);

	if (str1.size() != 4 || str2.size() != 2 || str3.size() != 2
		|| checkDigit(str1, 1) || checkDigit(str2, 2) || checkDigit(str3, 3))
		throwing("Error: bad input => " + str.substr(0, str.size()));
}

void	BitcoinExchange::reading()
{
	size_t n;
	while (std::getline(inpF, line))
	{
		try
		{
			empty = false;
			n = line.find(" | ", 0);
			if (n == std::string::npos)
				throwing("Error: bad input => " + line.substr(0, line.size()));
			std::string str = line.substr(n + 3, (line.size() - (n + 3)));
			if (str.empty())
				throwing("Error: not a number");
			checkValue(str);
			str = line.substr(0, n);
			checkDate(str);
			std::cout << str << " => " << line << std::endl;
		}
		catch(std::string &e)
		{
			std::cout << e << std::endl;
		}
	}
}

void	BitcoinExchange::btc()
{
	try
	{
		inpF.open(av1);
		if (!inpF.is_open())
			throwing("Error: could not open file.");
		std::getline(inpF, line);
		if (line.empty())
			throwing("Error: empty file");
		else if (line != "date | value")
			throwing("Error: enter <date | value>");
		empty = true;
		BitcoinExchange::reading();
		if (empty)
			throwing("Error: empty file");
	}
	catch(std::string &e)
	{
		std::cout << e << std::endl;
	}
}

// void	BitcoinExchange::get_data();
// void	BitcoinExchange::get_inp();