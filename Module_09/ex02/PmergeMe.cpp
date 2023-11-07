/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 07:50:27 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/11/07 09:34:10 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

void	PmergeMe::recursion()
{
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

	//######### return from rec
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
	std::cout << "\nback to " << nbr-- << ", " ;
	if (!tmpSimplePair.first.empty())
		print(tmpSimplePair);
	else
		std::cout << ".   tmp is   empty\n";
	
//----------------------------------------
	//######## BACK FROM REC
	size_t half;
	size_t i;
	if (mainPairs.size() % 2 != 0 && mainPairs.size() != 1)
	{
		std::cout << "la\n";
		mainPairs.pop_back();
		print(1);
	}
	//####### SPLIT MAINPAIRS
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
	if (mainPairs.size() == 1 && !tmpSimplePair.first.empty() && !tmpSimplePair.second.empty())
	{
		std::cout << "##########################\n";
		if (mainPairs.front().second.back() < tmpSimplePair.second.back())
			mainPairs.push_back(tmpSimplePair);
		else
			mainPairs.push_front(tmpSimplePair);
		// deqOfSplitedPair.push_back(mainPairs.front().first.front());
		// deqOfSplitedPair.push_back(mainPairs.front().second.front());
		return;
	}
	deqOfSplitedPair.push_back(mainPairs.front().first);
	deqOfSplitedPair.push_back(mainPairs.front().second);
	dpdIt = mainPairs.begin();
	dpdIt++;
	for (; dpdIt != mainPairs.end(); dpdIt++)
	{
		deqOfSplitedPair.push_back(dpdIt->second);
		pending.push_back(dpdIt->first);
	}
	
	copyOfSplitedPair = deqOfSplitedPair;
	for (pIt = pending.begin(); pIt != pending.end(); pIt++)
	{
		for (sIt = deqOfSplitedPair.begin(), sIt2 = copyOfSplitedPair.begin(); sIt + 1 != deqOfSplitedPair.end(); sIt++, sIt2++)
		{
			if (pIt->back() > sIt->back() && pIt->back() < (sIt + 1)->back())
				copyOfSplitedPair.insert((sIt2 + 1), *pIt);
			else if (sIt + 1 == deqOfSplitedPair.end())
				copyOfSplitedPair.insert(copyOfSplitedPair.end(), *pIt);
		}
	}
	std::cout  << "\n deq splited     [";
	for (ddIt = deqOfSplitedPair.begin(); ddIt != deqOfSplitedPair.end(); ddIt++)
	{
		for (dIt = ddIt->begin(); dIt != ddIt->end(); dIt++)
			std::cout << *dIt << " ";
		std::cout  << ", ";
	}
	std::cout  << "]";
		std::cout  << "\n pending     [";
	for (ddIt = pending.begin(); ddIt != pending.end(); ddIt++)
	{
		for (dIt = ddIt->begin(); dIt != ddIt->end(); dIt++)
			std::cout << *dIt << " ";
		std::cout  << ", ";
	}
	std::cout  << "]\n";
	pending.clear();
	deqOfSplitedPair = copyOfSplitedPair;
	copyOfSplitedPair = deqOfSplitedPair;
	for (sIt = deqOfSplitedPair.begin(), sIt2 = copyOfSplitedPair.begin(); sIt + 1 != deqOfSplitedPair.end(); sIt++, sIt2++)
	{
		if (!tmpSimplePair.first.empty() && !tmpSimplePair.second.empty())
		{
			// std::cout << "#############  " << tmpSimplePair.first.back() << " " << tmpSimplePair.second.back() << '\n';
			if (tmpSimplePair.second.back() > sIt->back() && tmpSimplePair.second.back() < (sIt + 1)->back())
			{
				copyOfSplitedPair.insert(sIt2 + 1, tmpSimplePair.first);
				copyOfSplitedPair.insert(sIt2 + 2, tmpSimplePair.second);
				tmpSimplePair.first.clear();
				tmpSimplePair.second.clear();
			}
		}
	}

	deqOfSplitedPair = copyOfSplitedPair;
	copyOfSplitedPair.clear();
	
	std::cout  << "\n deq splited     [";
	for (ddIt = deqOfSplitedPair.begin(); ddIt != deqOfSplitedPair.end(); ddIt++)
	{
		for (dIt = ddIt->begin(); dIt != ddIt->end(); dIt++)
			std::cout << *dIt << " ";
		std::cout  << ", ";
	}
	std::cout  << "]\n";
	
	// int y = 1;
	for (ddIt = deqOfSplitedPair.begin(); ddIt != deqOfSplitedPair.end(); ddIt += 2)
	{
		// std::cout << "ha" << '\n';
		for (dIt = ddIt->begin(); dIt != ddIt->end(); dIt++)
			simplePair.first.push_back(*dIt);
		for (dIt = (ddIt + 1)->begin(); dIt != (ddIt + 1)->end(); dIt++)
			simplePair.second.push_back(*dIt);
		copyOfPairs.push_back(simplePair);
		simplePair.first.clear();
		simplePair.second.clear();
	}

	std::cout << "##### main befor  ";
	print(1);
	std::cout << "##### main       ";
	
	mainPairs = copyOfPairs;
	print(1);
		while (1);
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
		TmpOfDeq.push_back(NbrsOfDeq.back().back());
		NbrsOfDeq.pop_back();
		std::cout << "TmpOfDeq:            \"" << TmpOfDeq.front() << "\"\n";
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

	//####### COPY PAIRS TO NBRS
	for (dpdIt = mainPairs.begin(); dpdIt != mainPairs.end(); dpdIt++)
	{
		sortedNbrsOfDeq.push_back(dpdIt->first.back());
		sortedNbrsOfDeq.push_back(dpdIt->second.back());
	}

	//print
	std::cout << "SORTED NBRS           [";
	for (dIt = sortedNbrsOfDeq.begin(); dIt != sortedNbrsOfDeq.end(); dIt++)
	{
			std::cout << *dIt << " ";
	}
		std::cout << "] ";
	std::cout << '\n';
}

PmergeMe::PmergeMe(const PmergeMe &mer)
{
	*this = mer;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &mer)
{
	if (this != &mer)
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
