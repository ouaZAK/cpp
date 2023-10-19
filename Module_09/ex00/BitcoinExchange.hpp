/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 09:11:42 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/10/19 10:23:51 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <fstream>
#include <iomanip>
#include <map>

class BitcoinExchange
{
	private:
		std::map<std::string, double>	map;
		std::ifstream					inpF;
		std::string 					line;
		std::string						tmp;
		std::string						av1;
		double							d;
		bool							empty;
		BitcoinExchange();
		void	reading();
	public:
		BitcoinExchange(char *av);
		BitcoinExchange(const BitcoinExchange &bitc);
		BitcoinExchange &operator=(const BitcoinExchange &bit);
		~BitcoinExchange();

		void	btc();
		// void	get_data();
		// void	get_inp();
};
