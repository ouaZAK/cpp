/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 07:50:27 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/10/31 09:29:09 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(char **av)
{
	for (int i = 1; av[i]; i++)
	{
		str = static_cast<std::string>(av[i]);
		PmergeMe::checkErrors();
	}
	PmergeMe::recursion();
}

PmergeMe::PmergeMe(const PmergeMe &mer)
{
	if (this != &mer)
		*this = mer;
}
PmergeMe &PmergeMe::operator=(const PmergeMe &mer)
{
	(void)mer;
	return (*this);
}

PmergeMe::~PmergeMe()
{
}

//remove this after #############
std::ostream &operator<<(std::ostream &out, const std::deque<int> &dec)
{
	std::deque<int>::const_iterator cit;
	for (cit = dec.begin(); cit != dec.end(); cit++)
		out << *cit;
	return (out);
}

std::deque< std::deque<int> > PmergeMe::getPairs()
{
	return pairs;
}

//#################

void	PmergeMe::checkErrors()
{
	std::string::iterator it;
	for (it = str.begin(); it != str.end(); it++)
		if (!std::isdigit(*it))
			throw (std::invalid_argument("Error: invalid argument"));
	std::stringstream ss;
	ss << str;
	ss >> nbr;
	x.push_back(nbr);
	pairs.push_back(x);
	x.clear();
	// std::cout << pairs.at(0) << '\n';
}

void	PmergeMe::recursion()
{
	std::deque<std::pair<std::deque<int>, std::deque<int>> > pair;
	pair.push_back(std::make_pair(pairs.at(0), pairs.at(1)));
	std::cout << first //lets try to print first pair and second one
}