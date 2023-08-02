/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 13:21:57 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/07/31 12:38:18 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

int main()
{
	PhoneBook phone;
	std::string av;
	int	stop;
	int	n;

	n = 0;
	do
	{
		stop = 1;
		if (std::cin.eof())
			break;
		std::cout << "type ADD, SEARCH or EXIT : ";
		std::getline(std::cin, av);
		if (std::cin.eof())
			break;
		if (!(int)phone.check(av))
		{
			std::cout << "entre valid input" << std::endl;
			continue;
		}
		else if ((int)phone.check(av) == EXIT)
			exit(0);
		else if ((int)phone.check(av) == ADD)
		{
			for (int i = 0; i < 5; i++)
				phone.adding(av, i, n % 8);
			n++;
		}
		else if ((int)phone.check(av) == SEARCH)
		{
			if (!n)
			{
				std::cout << "empty" << std::endl;
				continue ;
			}
			else
				phone.display(n);
			do
			{
				std::cout << "choose an index number : ";
				std::getline(std::cin, av);
				if (std::cin.eof())
					break;
				if (phone.check_valid(av, n))
					stop = 0;
				else
					std::cout << "wrong index\n";
			}
			while (stop == 1);
		}
	}
	while (1);
}