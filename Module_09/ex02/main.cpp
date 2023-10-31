/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 07:54:14 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/10/31 09:16:47 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cout << "Error: enter numbers to sort" << std::endl;
		return (0);
	}
	try
	{
		PmergeMe merge(av);

		std::deque< std::deque<int> > tmp = merge.getPairs();
		std::deque< std::deque<int> >::iterator it;
		for (it = tmp.begin(); it != tmp.end(); it++)
			std::cout << "[" << *it << "] " ;
		std::cout << '\n';
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}