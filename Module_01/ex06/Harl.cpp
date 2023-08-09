/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 17:15:22 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/08/09 16:55:44 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}


void	Harl::debug(void)
{
	std::cout	<< "[ DEBUG ]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger.\n"
				<<"I really do!\n" << std::endl;
}

void	Harl::info(void)
{
	std::cout	<< "[ INFO ]\n cannot believe adding extra bacon costs more money.\n"
				<< "You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n" << std::endl;
}

void	Harl::warning(void)
{
	std::cout	<< "[ WARNING ]\nI think I deserve to have some extra bacon for free.\n"
				<<"I've been coming for years whereas you started working here since last month\n" << std::endl;
}

void	Harl::error(void)
{
	std::cout << "[ ERROR ]\nThis is unacceptable, I want to speak to the manager now.\n" << std::endl;
}

void	Harl::complain(std::string level)
{
	typedef void (Harl::*ptr)();
	int i = 0;
	
	ptr comp[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string complains[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	
	while (i < 4 && complains[i] != level)
		i++;
	switch (i)
	{
		case 0:
			(this->*comp[0])();
			(this->*comp[1])();
			(this->*comp[2])();
			(this->*comp[3])();
			break;
		case 1:
			(this->*comp[1])();
			(this->*comp[2])();
			(this->*comp[3])();
			break;
		case 2:
			(this->*comp[2])();
			(this->*comp[3])();
			break;
		case 3:
			(this->*comp[3])();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]"<< std::endl;
	}
}
