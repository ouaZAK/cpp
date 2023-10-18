/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 09:11:28 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/10/18 15:31:59 by zouaraqa         ###   ########.fr       */
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

void	BitcoinExchange::btc()
{
	inpF.open(av1);
	if (!inpF.is_open())
		return ;
	std::getline(inpF, line);
	if (line.empty())
	{
		std::cout << "Error: empty file" << std::endl;
		return ;
	}
	else if (line != "date | value")
	{
		std::cout << "Error: enter <date | value>" << std::endl;
		return ;
	}
	empty = true;
	checkErrors();
}

void	BitcoinExchange::checkErrors()
{
	int count;
	size_t n;
	while (std::getline(inpF, line))
	{
		empty = false;
		n = 0;
		count = 0;
		while (line.find('-', n) != std::string::npos)
		{
			n = line.find('-', n + 1);
			if (n != std::string::npos)
				count++;
		}
		try
		{
			if (count < 2)
				throw (1);
			else if (count > 2)
				throw (2);
			std::cout << line << std::endl;
		}
		catch(int &x)
		{
			if (x == 1)
				std::cout << "Error: bad input => " << line.substr(0, line.find('|', 0)) << std::endl;
			else if (x == 2)
				std::cout << "Error: not a positive number" << std::endl;
		}
		
	}
	if (empty)
	{
		std::cout << "Error: empty file" << std::endl;
		return ;
	}
}

// void	BitcoinExchange::get_data();
// void	BitcoinExchange::get_inp();