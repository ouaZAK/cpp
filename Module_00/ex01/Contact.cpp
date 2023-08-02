/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 13:28:49 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/07/31 12:47:39 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(){}
Contact::~Contact(){}

void	Contact::set_index(int n)
{
	this->index = n;
}

int	Contact::get_index(void)
{
	return (this->index);
}

void	Contact::set_str(std::string str, int i)
{
	if (i == 0)
		this->first_name = str;
	else if (i == 1)
		this->last_name = str;
	else if (i == 2)
		this->nickname = str;
	else if (i == 3)
		this->phone_number = str;
	else if (i == 4)
		this->darkest_secret = str;
}

void	print(std::string str)
{
	int size;

	size = str.size();
	if (size < 9)
		std::cout << std::setw(10) << str;
	else
		std::cout << str.substr(0, 9) + ".";
}

void	Contact::get_str(void)
{
	std::cout	<< "|" << std::setw(10) << this->index << "|";
	print(this->first_name);
	std::cout	<< "|";
	print(this->last_name);
	std::cout	<< "|";
	print(this->nickname);
	std::cout	<< "|";
	std::cout	<< std::endl;
}

void	Contact::get_cnt(void)
{
	std::cout << "first name : " << this->first_name << std::endl;
	std::cout << "last name : " << this->last_name << std::endl;
	std::cout << "nickname : " << this->nickname << std::endl;
	std::cout << "phone number : " << this->phone_number << std::endl;
	std::cout << "darkest secret : " << this->darkest_secret << std::endl;
}
