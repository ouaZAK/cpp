/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 13:28:43 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/07/31 12:47:16 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(){}
PhoneBook::~PhoneBook(){}

int PhoneBook::check_valid(std::string av,int n)
{
	char s[av.length()];
	int i;

	av.copy(s, av.length());
	i = atoi(s);
	if (i >= 1 && i <= 8 && i <= n)
	{
		this->contacts[i - 1].get_cnt();
		return (1);
	}
	return (0);
}

int PhoneBook::check(std::string av)
{
	if (av == "ADD")
		return (ADD);
	else if (av == "SEARCH")
		return (SEARCH);
	else if (av == "EXIT")
		return (EXIT);
	return (0);
}

std::string	get_input(std::string av, std::string str)
{
	int stop;

	stop = 1;
	do
	{
		std::cout << str;
		std::getline(std::cin, av);
		if (std::cin.eof())
			break ;
		if (av.empty())
			std::cout << "write something"<< std::endl;
		else
			stop = 0;
	}while (stop);
	return (av);
}

void	PhoneBook::adding(std::string av, int i, int n)
{
	if (i == 0)
	{
		av = get_input(av, "enter first name : ");
		this->contacts[n].set_str(av, i);
	}
	else if (i == 1)
	{
		if (std::cin.eof())
			return;
		av = get_input(av, "enter last name : ");
		this->contacts[n].set_str(av, i);
	}
	else if (i == 2)
	{
		if (std::cin.eof())
			return;
		av = get_input(av, "enter nickname : ");
		this->contacts[n].set_str(av, i);
	}
	else if (i == 3)
	{
		if (std::cin.eof())
			return;
		av = get_input(av, "enter phone number : ");
		this->contacts[n].set_str(av, i);
	}
	else if (i == 4)
	{
		if (std::cin.eof())
			return;
		av = get_input(av, "enter darkest secret : ");
		this->contacts[n].set_str(av, i);
	}
	this->contacts[n].set_index(n + 1);
}

void	PhoneBook::display(int n)
{
	std::cout	<< "|" << std::setw(10) << "index"
				<< "|" << std::setw(10) << "first name"
				<< "|" << std::setw(10) << "last name"
				<< "|" << std::setw(10) << "nickname"
				<< "|" << std::endl;
	if (n > 8)
		n = 8;
	for (int i = 0; i < n; i++)
		this->contacts[i].get_str();
}
