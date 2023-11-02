/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 07:50:27 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/11/02 11:33:41 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

void	PmergeMe::checkAndStock()
{
	std::string::iterator it;
	for (it = str.begin(); it != str.end(); it++)
		if (!std::isdigit(*it))
			throw (std::invalid_argument("Error: invalid argument"));
	std::stringstream ss;
	ss << str;
	ss >> nbr;
	tmpDeque.push_back(nbr);
	dequeNbrs.push_back(tmpDeque);
	tmpDeque.clear();
}

void	PmergeMe::recursion()
{
	nbr++;
	std::cout << nbr << '\n';
	//sort pairs
	for (pit = pair.begin(); pit != pair.end(); pit++)
		if (pit->first.back() > pit->second.back())
			std::swap(pit->first, pit->second);

	//print
	print2();
	
	//must be pair
	if (pair.size() % 2 != 0 && pair.size() != 1)
	{
		copyFirst = pair.back().first;
		copySecond = pair.back().second;
	std::cout << "rest:             [" << copyFirst.front() << ", " << copySecond.front() << "]\n";
		pair.pop_back();
	}
	
	//print
	if (pair.size() % 2 != 0 && pair.size() != 1)
		print();
	else
		print2();
	
	// std::cout << pair.size() << '\n';
	//copy to stock of pairs
	if (pair.size() == 1)
		return ;

	std::deque<int>::iterator dit,dit2;
	// dit = pair.front().first.begin();
	pit = pair.begin();
	
	while (pit != pair.end())
	{
		dit = pit->first.begin();
		// dit = pair.front().first.begin();
		for (dit = pit->first.begin(); dit != pit->first.end(); dit++)
		{
			stock.first.push_back(*dit);
		// std::cout << *dit << ' ' << *(++dit) << '\n';
		}
		
			// stock.first.push_back(*dit2);
		// for (dit = pit->second.begin(), dit2 = pit->second.begin(); dit != pit->second.begin(); dit++)
		// {
		// 	stock.first.push_back(*dit);
		// 	stock.first.push_back(*dit2);
		// }
		// if (pit == pair.end())
		// 	break;
		// for (dit = pit->first.begin(); dit != pit->first.end(); dit++)
		// 	stock.second.push_back(*dit);
		// for (dit = pit->second.begin(); dit != pit->second.begin(); dit++)
		// 	stock.second.push_back(*dit);
		nextPair.push_back(stock);
		// for (std::deque<int>::iterator i = stock.first.begin(); i != stock.first.end(); i++)
		// 	std::cout << *i << ' ';
		// for (std::deque<int>::iterator i = stock.second.begin(); i != stock.second.end(); i++)
		// 	std::cout << *i << ' ';
		// std::cout << '\n';
		stock.first.clear();
		stock.second.clear();
		pit++;
	}
	// size_t x = pair.size() / 2;
	// for (pit = pair.begin(); pit != pair.end(); pit++)
	// {
	// 	while (!pit->first.empty() && pair.size() > x)
	// 	{
	// 		stock.first.push_back(pit->first.front());
	// 		stock.first.push_back(pit->second.front());
	// 		pair.pop_front();
	// 	}
	// }
	// // while(1);
	// for (pit = pair.begin(); pit != pair.end(); pit++)//segfult
	// {
	// 	while (!pit->first.empty() && pair.size() > 0)
	// 	{
	// 		stock.second.push_back(pit->first.front());
	// 		stock.second.push_back(pit->second.front());
	// 		pair.pop_front();
	// 	}
	// }


	pair.clear();
	pair = nextPair;
	pit = pair.begin();
	// pair.insert(pit, stock);
	// std::copy(stock.first.begin(), stock.first.end(), pit->first.begin());
	// for (i = stock.first.begin(); i != stock.first.end(); i++)
	// {
	// 	pit->first.push_back(*i);
	// 	pit++;
	// }
	// pit = pair.begin();
	// for (i = stock.second.begin(); i != stock.second.end(); i++)
	// {
	// 	pit->second.push_back(*i);
	// 	pit++;
	// }
	// if (pair.begin() != pair.end())
	// 	std::cout << pit->first.front() << '\n';
	for (pit = pair.begin(); pit != pair.end(); pit++)
	{
	std::cout << "[";
		for (dit = pit->first.begin(); dit != pit->first.end(); dit++)
			std::cout << *dit << " ";
		std::cout << ',';
		for (dit = pit->second.begin(); dit != pit->second.end(); dit++)
			std::cout << *dit << "]";
	}
	std::cout << "\n";
	// recursion();
}

PmergeMe::PmergeMe(char **av)
{
	for (int i = 1; av[i]; i++)
	{
		str = static_cast<std::string>(av[i]);
		PmergeMe::checkAndStock();
	}
	
	//print
	std::cout << "at start:         ";
	for (it = dequeNbrs.begin(); it != dequeNbrs.end(); it++)
		std::cout << "\"" << *it << "\" " ;
	std::cout << '\n';

	if (dequeNbrs.size() % 2)
	{
		rest.push_back(dequeNbrs.back().back());
		dequeNbrs.pop_back();
		std::cout << "rest:             \"" << rest.front() << "\"\n";
	}

	//create first pair
	it = dequeNbrs.begin();
	while (it != dequeNbrs.end())
	{
		pair.push_back(std::make_pair(*it, *(it + 1)));
		it += 2;
	}
	nbr = -1;
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
std::deque< std::deque<int> > PmergeMe::getdequeNbrs()
{
	return dequeNbrs;
}
void	PmergeMe::print()
{
	std::cout << "make dequeNbrs:   ";
	for (pit = pair.begin(); pit != pair.end(); pit++)
		std::cout << "[" << pit->first.front() << ", " << pit->second << "] ";
	std::cout << '\n' << "tmp:            \"" << copyFirst.front() << ' ' << copySecond.front() << "\"\n";
}
void	PmergeMe::print2()
{
	std::cout << "first pairs:      ";
	for (pit = pair.begin(); pit != pair.end(); pit++)
		std::cout << "[" << pit->first.front() << ", " << pit->second << "] ";
	std::cout << '\n';
}
//#################
