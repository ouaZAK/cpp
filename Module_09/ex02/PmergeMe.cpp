/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 07:50:27 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/11/03 12:04:30 by zouaraqa         ###   ########.fr       */
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
	TmpOfDeq.push_back(nbr);
	NbrsOfDeq.push_back(TmpOfDeq);
	TmpOfDeq.clear();
}

void	PmergeMe::recursion()
{
	//need it to be in stack frame of eache rec
	// pairOfDeque						tmpSimplePair;

	nbr++;
	std::cout << "\ndept;      	      " << nbr << '\n';

	//sort pairs
	for (dpdIt = mainPairs.begin(); dpdIt != mainPairs.end(); dpdIt++)
		if (dpdIt->first.back() > dpdIt->second.back())
			std::swap(dpdIt->first, dpdIt->second);

	//print
	print2();
	//must be pair
	if (mainPairs.size() % 2 != 0 && mainPairs.size() != 1)
	{
		tmpSimplePair = mainPairs.back();
		mainPairs.pop_back();
		// FirstOfSimplePair = mainPairs.back().first;
		// SecondOfSimplePair = mainPairs.back().second;
	std::cout << "RestOfDeq:             [" << tmpSimplePair.first.front() << ", " << tmpSimplePair.second.front() << "]\n";
	}
	
	//print
	if (mainPairs.size() % 2 != 0 && mainPairs.size() != 1)
		print();
	else
		print2();
	
	// std::cout << pair.size() << '\n';
	//copy to stock of pairs
	if (mainPairs.size() == 1)
		return ;

	copyOfPairs.clear();
	for (dpdIt = mainPairs.begin(); (dpdIt ) != mainPairs.end(); dpdIt += 2)
	{
		for (dit = dpdIt->first.begin(); dit != dpdIt->first.end(); dit++)
		{
			simplePair.first.push_back(*dit);
			// std::cout << simplePair.first.back() << '\n';
		}
		for (dit = dpdIt->second.begin(); dit != dpdIt->second.end(); dit++)
		{
			simplePair.first.push_back(*dit);
			// std::cout << simplePair.first.back() << '\n';
		}
		for (dit = (dpdIt + 1)->first.begin(); dit != (dpdIt + 1)->first.end(); dit++)
		{
			simplePair.second.push_back(*dit);
			// std::cout << simplePair.second.back() << '\n';
		}
		for (dit = (dpdIt + 1)->second.begin(); dit != (dpdIt + 1)->second.end(); dit++)
			simplePair.second.push_back(*dit);
		copyOfPairs.push_back(simplePair);
		simplePair.first.clear();
		simplePair.second.clear();
	}

	mainPairs = copyOfPairs;
	copyOfPairs.clear();
	std::cout << "final:                ";
	for (dpdIt = mainPairs.begin(); dpdIt != mainPairs.end(); dpdIt++)
	{
	std::cout << "[";
		for (dit = dpdIt->first.begin(); dit != dpdIt->first.end(); dit++)
			std::cout << *dit << " ";
		std::cout << ',';
		for (dit = dpdIt->second.begin(); dit != dpdIt->second.end(); dit++)
			std::cout << *dit << ' ';
		std::cout << "]";
	}
	std::cout << "\n";
	recursion();
	std::cout << "back to " << nbr-- << "    tmp is [" << tmpSimplePair.first.front() << ',' << tmpSimplePair.second.front() << "]\n";
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
	for (ddIt = NbrsOfDeq.begin(); ddIt != NbrsOfDeq.end(); ddIt++)
		std::cout << "\"" << *ddIt << "\" " ;
	std::cout << '\n';

	if (NbrsOfDeq.size() % 2)
	{
		RestOfDeq.push_back(NbrsOfDeq.back().back());
		NbrsOfDeq.pop_back();
		std::cout << "RestOfDeq:             \"" << RestOfDeq.front() << "\"\n";
	}

	//create first mainPairs
	ddIt = NbrsOfDeq.begin();
	while (ddIt != NbrsOfDeq.end())
	{
		mainPairs.push_back(std::make_pair(*ddIt, *(ddIt + 1)));
		ddIt += 2;
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
	return NbrsOfDeq;
}
void	PmergeMe::print()
{
	std::cout << "make dequeNbrs:   ";
	for (dpdIt = mainPairs.begin(); dpdIt != mainPairs.end(); dpdIt++)
		std::cout << "[" << dpdIt->first.front() << ", " << dpdIt->second << "] ";
	std::cout << '\n' << "tmp:            \"" << simplePair.first.front() << ' ' << simplePair.second.front() << "\"\n";
}
void	PmergeMe::print2()
{
	std::cout << "first mainPairs:      ";
	for (dpdIt = mainPairs.begin(); dpdIt != mainPairs.end(); dpdIt++)
		std::cout << "[" << dpdIt->first.front() << ", " << dpdIt->second << "] ";
	std::cout << '\n';
}
//#################
