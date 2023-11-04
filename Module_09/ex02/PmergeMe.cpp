/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 07:50:27 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/11/04 13:04:59 by zouaraqa         ###   ########.fr       */
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
	pairOfDeque						tmpSimplePair;

	nbr++;
	std::cout << "\ndept;      	      " << nbr << '\n';

	//########  SORT PAIRS
	for (dpdIt = mainPairs.begin(); dpdIt != mainPairs.end(); dpdIt++)
		if (dpdIt->first.back() > dpdIt->second.back())
			std::swap(dpdIt->first, dpdIt->second);

	//########  PRINT  
	std::cout << "first mainPairs:      ";
	print(1);

	//######## MUST BE PAIR
	if (mainPairs.size() % 2 != 0 && mainPairs.size() != 1)
	{
		tmpSimplePair = mainPairs.back();
		mainPairs.pop_back();
		print(tmpSimplePair);
	}
	
	//########  PRINT
	std::cout << "second mainPairs:     ";
	if (mainPairs.size() % 2 != 0 && mainPairs.size() != 1)
		print(0);
	else
		print(1);

	if (mainPairs.size() == 1)
		return ;

	//######## COPY mainPairs TO copyOfPairs
	copyOfPairs.clear();
	for (dpdIt = mainPairs.begin(); (dpdIt ) != mainPairs.end(); dpdIt += 2)
	{
		//copy first and second (of the begin in mainPairs) deques in simplepair first
		for (dIt = dpdIt->first.begin(); dIt != dpdIt->first.end(); dIt++)
			simplePair.first.push_back(*dIt);
		for (dIt = dpdIt->second.begin(); dIt != dpdIt->second.end(); dIt++)
			simplePair.first.push_back(*dIt);

		//copy first and second (of the (begin + 1) in mainPairs) deques in simplepair second
		for (dIt = (dpdIt + 1)->first.begin(); dIt != (dpdIt + 1)->first.end(); dIt++)
			simplePair.second.push_back(*dIt);
		for (dIt = (dpdIt + 1)->second.begin(); dIt != (dpdIt + 1)->second.end(); dIt++)
			simplePair.second.push_back(*dIt);

		copyOfPairs.push_back(simplePair);
		simplePair.first.clear();
		simplePair.second.clear();
	}
	mainPairs = copyOfPairs;
	copyOfPairs.clear();

	//######## PRINT
	std::cout << "final:                ";
	print(1);

	recursion();
	std::cout << "\nback to " << --nbr << ", " ;
	if (!tmpSimplePair.first.empty())
		print(tmpSimplePair);
	else
		std::cout << ".   tmp is   empty\n";
	

	//######## BACK FROM REC
	size_t half;
	size_t i;

	for (dpdIt = mainPairs.begin(); dpdIt != mainPairs.end(); dpdIt++)
	{
		half = dpdIt->first.size() / 2;
		i = 0;
		for (dIt = dpdIt->first.begin(); dIt != dpdIt->first.end(); dIt++)
		{
			if (i++ < half)
				splitedPair.first.push_back(*dIt);
			else
				splitedPair.second.push_back(*dIt);
		}
		copyOfPairs.push_back(splitedPair);
		splitedPair.first.clear();
		splitedPair.second.clear();

		i = 0;
		for (dIt = dpdIt->second.begin(); dIt != dpdIt->second.end(); dIt++)
		{
			if (i++ < half)
				splitedPair.first.push_back(*dIt);
			else
				splitedPair.second.push_back(*dIt);
		}
		copyOfPairs.push_back(splitedPair);
		splitedPair.first.clear();
		splitedPair.second.clear();
	}
	mainPairs = copyOfPairs;
	copyOfPairs.clear();

	//rpint
	std::cout << "after spliting        ";
	print(1);
}

PmergeMe::PmergeMe(char **av)
{
	for (int i = 1; av[i]; i++)
	{
		str = static_cast<std::string>(av[i]);
		PmergeMe::checkAndStock();
	}

	if (NbrsOfDeq.size() == 1)
		return ;

	//######## PRINT
	std::cout << "at start:             ";
	for (ddIt = NbrsOfDeq.begin(); ddIt != NbrsOfDeq.end(); ddIt++)
		std::cout << "\"" << *ddIt << "\" " ;
	std::cout << '\n';

	//########  IF NOT PAIR STORE LAST NBR
	if (NbrsOfDeq.size() % 2)
	{
		RestOfDeq.push_back(NbrsOfDeq.back().back());
		NbrsOfDeq.pop_back();
		std::cout << "RestOfDeq:            \"" << RestOfDeq.front() << "\"\n";
	}

	//########  CREAT FIRST MAIN PAIRS
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
void	PmergeMe::print(int x)
{
	for (dpdIt = mainPairs.begin(); dpdIt != mainPairs.end(); dpdIt++)
	{
		std::cout << "[";
		for (dIt = dpdIt->first.begin(); dIt != dpdIt->first.end(); dIt++)
			std::cout << *dIt << " ";
			std::cout << ", ";
		for (dIt = dpdIt->second.begin(); dIt != dpdIt->second.end(); dIt++)
			std::cout << *dIt << " ";
		std::cout << "] ";
	}
	std::cout << '\n';
	if (!x)
		std::cout << '\n' << "tmp:            \"" << simplePair.first.front() << ' ' << simplePair.second.front() << "\"\n";
}
void	PmergeMe::print(pairOfDeque tmpSimplePair)
{
	dequeOfPairsOfDeque stock;
	stock.push_back(tmpSimplePair);
	std::cout << "rest		      ";
	for (dpdIt = stock.begin(); dpdIt != stock.end(); dpdIt++)
	{
		std::cout << "[";
		for (dIt = dpdIt->first.begin(); dIt != dpdIt->first.end(); dIt++)
			std::cout << *dIt << " ";
			std::cout << ", ";
		for (dIt = dpdIt->second.begin(); dIt != dpdIt->second.end(); dIt++)
			std::cout << *dIt << " ";
		std::cout << "] ";
	}
	std::cout << '\n';
}
//#################
