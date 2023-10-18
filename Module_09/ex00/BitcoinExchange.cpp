/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 09:11:28 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/10/18 11:04:07 by zouaraqa         ###   ########.fr       */
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
	std::ifstream inpF(av1);
	if (!inpF.is_open())
		return ;
	std::getline(inpF, line);
	if (line.empty())
		std::cout << "Error: empty file" << std::endl;
	if (line != "date | value")
		std::cout << "Error: enter <date | value>" << std::endl;
	checkErrors();
}

void	BitcoinExchange::checkErrors() const
{
	
}

// void	BitcoinExchange::get_data();
// void	BitcoinExchange::get_inp();