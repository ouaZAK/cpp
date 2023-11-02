/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 09:11:28 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/11/02 10:55:53 by zouaraqa         ###   ########.fr       */
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
	empty = bitc.empty;
	d = bitc.d;
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
}

void	throwing(std::string str)
{
	throw (std::invalid_argument(str));
}

void	BitcoinExchange::checkValue(std::string &str)
{
	int qCount = 0;
	int count = 0;

	for (std::string::iterator it = str.begin(); it != str.end(); it++)
	{
		if (*it != '.' && *it != '-' && *it != '+')
			if (!std::isdigit(*it))
				throwing("Error: not a number");
		if (*it == '.')
		{
			if ((!std::isdigit(*(it - 1)) && !std::isdigit(*(it + 1))))//check if '.' is alone 
				throwing("Error: not a number");
			count++;
		}
		if (*it == '-' || *it == '+')
		{
			qCount++;
			if (it != str.begin() || (it == str.begin() && str.size() == 1))// if - is not in begin like 1- or 1+2 or only +
				throwing("Error: not a number");
			else if (it == str.begin() && *it != '+')
				throwing("Error: not a positive number.");
		}
		if (count > 1 || qCount > 1)
			throwing("Error: not a number");
	}

	d = std::strtod(str.c_str(), NULL);
	if (d > 1000)
		throwing("Error: too large a number.");
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
	std::string strV;
	std::string strD;
	std::map<std::string, double>::iterator it;

	while (std::getline(inpF, line))
	{
		try
		{
			empty = false;
			n = line.find(" | ", 0);
			if (n == std::string::npos)
				throwing("Error: bad input => " + line.substr(0, line.size()));
			strV = line.substr(n + 3, (line.size() - (n + 3)));
			if (strV.empty())
				throwing("Error: not a number");
			checkValue(strV);
			strD = line.substr(0, n);
			checkDate(strD);
			it = map.upper_bound(strD);
			if (it != map.begin())
				it--;
			std::cout << strD << " => " << strV << " = " << (d * it->second) << std::endl;
		}
		catch(std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	inpF.close();
}

void	BitcoinExchange::storeData()
{
	std::string date;
	size_t		len;

	inpF.open("Data.csv");
	if (!inpF.is_open())
		throwing("Error: could not open Data.scv file.");
	std::getline(inpF, line);
	if (line.empty())
		throwing("Error: empty file");
	while (std::getline(inpF, line))
	{
		date = line.substr(0, 10);
		len = line.size() - line.find(',', 0) - 1;
		d = std::strtod(line.substr(11, len).c_str() , NULL);
		map.insert(std::make_pair(date, d));
	}
	inpF.close();
}

void	BitcoinExchange::btc()
{
	try
	{
		BitcoinExchange::storeData();
		inpF.open(av1.c_str());
		if (!inpF.is_open())
			throwing("Error: could not open file.");
		std::getline(inpF, line);
		if (line.empty())
			throwing("Error: empty file");
		else if (line != "date | value")
			throwing("Error: enter <date | value>");
		empty = true;
		reading();
		if (empty)
			throwing("Error: empty file");
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
