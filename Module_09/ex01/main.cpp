/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 08:00:44 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/10/21 09:02:52 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <queue>

int	calculate(char c, int nbrs[2])
{
	switch (c)
	{
		case '-':
			return (nbrs[0] - nbrs[1]);
		case '+':
			return (nbrs[0] + nbrs[1]);
		case '*':
			return (nbrs[0] * nbrs[1]);
		case '/':
			return (nbrs[0] / nbrs[1]);
		default:
			return (nbrs[0] + nbrs[1]);
	}
}

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Error: enter <one argument>" << std::endl;
		return (0);
	}
	std::string str = av[1];
	std::deque<int> q;
	int count;
	int n = 0;
	int nbrs[2];
	int x = 2;
	q.push_back(9);
	q.push_back(8);
	q.push_back(7);
	for (std::string::iterator it = str.begin(); it != str.end(); it++)
	{
		count = 0;
		while (std::isspace(*it))
			it++;
		while (std::isdigit(*it))
			it++;
		if (!std::isdigit(*it) && !std::isspace(*it))
			count++;
		if (count)
		{
			q.push_front(calculate(*it, nbrs));
			x--;
		}
		if (!x)
			break ;
		nbrs[n] = q.front();
		n++;
		if (n == 2)
			n = 0;
		q.pop_front();
	}
	std::cout << q.front() << '\n';
	
	return (0);
}