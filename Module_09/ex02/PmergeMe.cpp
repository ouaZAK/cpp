/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 07:50:27 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/11/22 12:30:50 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void	printRest(deque restDeq, deque::iterator dIt)
{
	std::cout << "after res :      [";
	for (dIt = restDeq.begin(); dIt != restDeq.end(); dIt++)
		std::cout << *dIt << ", " ;
	std::cout << "]\n";
}

void PmergeMe::printpendChain()
{
	std::cout << "\nmainchain : >> " ;
	for (ddIt = mainChain.begin(); ddIt != mainChain.end(); ddIt++)
		print(*ddIt);
	std::cout << "\npend :      >> " ;
	if (!pend.empty())
	{
		for (pend::iterator it = pend.begin(); it != pend.end(); it++)
			print(it->first);
	}
	std::cout << '\n';
}

bool	comp(deque a, deque b)
{
	return (a.back() <= b.back());
}

PmergeMe::PmergeMe()
{
}

bool	PmergeMe::continueRec(deqOfDeq& arr)
{
	ddIt = arr.begin();
	if (ddIt->size() == cof && (ddIt + 1)->size() == cof)
		ddIt += 2;
	while (ddIt != arr.end())
	{
		if (ddIt->size() == cof && (ddIt + 1)->size() == cof)
			return true;
		++ddIt;
	}
	return (false);
}

void	PmergeMe::sort_pair_element(deque& temp)
{
	if (temp[0] > temp[1])
		std::swap(temp.front(), temp.back());
}

deqOfDeq	PmergeMe::makePair()
{
	deqOfDeq 	arr;
	deque 		temp;

	dIt = mainDeq.begin();
	while (dIt != mainDeq.end())
	{
		for (size_t i = 0; i < cof && dIt != mainDeq.end(); i++)
		{
			temp.push_back(*dIt);
			++dIt;
		}
		if (temp.size() == 2)
			sort_pair_element(temp);
		arr.push_back(temp);
		temp.clear();
	}
	return (arr);
}

void	PmergeMe::copyToMainDeq(deqOfDeq TmpDeq)
{
	mainDeq.clear();
	for (ddIt = TmpDeq.begin(); ddIt != TmpDeq.end(); ddIt++)
		for (dIt = ddIt->begin(); dIt != ddIt->end(); dIt++)
			mainDeq.push_back(*dIt);
}

void	PmergeMe::creatMainChainPend(deqOfDeq& arr)
{
	if (arr.back().size() != cof)
	{
		last = arr.back();
		arr.pop_back();
	}
	mainChain.clear();
	pend.clear();
	mainChain.push_back(arr.at(0));
	mainChain.push_back(arr.at(1));
	ddIt = arr.begin() + 2;
	while (ddIt != arr.end())
	{
		pendPair.second = mainChain.end();
		pendPair.first = (*ddIt);
		++ddIt;
		if (!ddIt->empty())
			pendPair.second = mainChain.insert(mainChain.end(), *ddIt);
		pend.push_back(pendPair);
		pendPair.first.clear();
		if (ddIt != arr.end())
			++ddIt;
	}
}

void	PmergeMe::sorting(deqOfDeq& arr)
{
	for (ddIt = arr.begin(); ddIt != arr.end(); ddIt++)
	{
		count++;
		if ((ddIt + 1) == arr.end() || ddIt->size() != (ddIt + 1)->size())
			break;
		if (ddIt->back() > (ddIt + 1)->back())
			std::swap(*ddIt, *(ddIt + 1));
		ddIt++;
	}
}

void	PmergeMe::update_iterator(deqOfDeq::iterator pos)
{
	pend::iterator it;

	for (it = pend.begin(); it != pend.end(); ++it)
	{
		if (pos >= it->second)
			++it->second;
	}
}

void	PmergeMe::inserting()
{
	deqOfDeq::iterator pos;


	for (pIt = pend.begin(); pIt != pend.end(); pIt++)
	{
		ddIt = std::lower_bound(mainChain.begin(), pIt->second, pIt->first, &comp);
		pos = mainChain.insert(ddIt, pIt->first);

		update_iterator(pos);
	}
	pend.clear();
	if (!last.empty())
	{
		mainChain.push_back(last);
		last.clear();
	}
}

//#####################################----------------------------------##########
//#####################################----------------------------------##########

void	PmergeMe::checkAndStock()
{
	std::string::iterator	it;
	deque::iterator			dIt2;

	for (it = str.begin(); it != str.end(); it++)
		if (!std::isdigit(*it))
			throw (std::invalid_argument("Error: invalid argument"));

	//stock nbrs
	std::stringstream ss;
	ss << str;
	ss >> nbr;
	mainDeq.push_back(nbr);

	//check repeated
	for (dIt = mainDeq.begin(); dIt != mainDeq.end(); dIt++)
		for (dIt2 = dIt + 1; dIt2 != mainDeq.end(); dIt2++)
			if (*dIt == *dIt2) 
				throw (std::invalid_argument("Error: no duplicated numbers"));
}

PmergeMe::PmergeMe(char **av)
{
	for (int i = 1; av[i]; i++)
	{
		str = static_cast<std::string>(av[i]);
		PmergeMe::checkAndStock();
	}

	if (mainDeq.size() == 1)
		return ;

// print
std::cout << "at start:             ";
print(mainDeq);
size_t x = mainDeq.size();
	nbr = -1;
	cof = 1;
	count = 0;
	std::cout << "\n-----------------------\n";
	//########## REC
	PmergeMe::recursion();

	std::cout << "\n------------####### SORTED I GUESS ########-----------\n\n";

//print
print(mainDeq);
size_t y = mainDeq.size();

// 	std::cout << '\n';
	std::cout << "count:  " <<  count << '\n';
	if (x == y)
	{
		if (std::is_sorted(mainDeq.begin(), mainDeq.end()))
			std::cout << "sorted\n";
		else
			std::cout << "not\n";
	}
	else
		std::cout << "not\n";
		
	
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
void	PmergeMe::print(deque mainDeq)
{
	std::cout << "[";
	for (dIt = mainDeq.begin(); dIt != mainDeq.end(); dIt++)
	{
			std::cout << *dIt;
			if (dIt + 1 != mainDeq.end())
				std::cout << ", ";
	}
	std::cout << "] ";
}
void	PmergeMe::print(deqOfDeq mainDeq)
{
	for (ddIt = mainDeq.begin(); ddIt != mainDeq.end(); ddIt++)
	{
		std::cout << "[";
		for (dIt = ddIt->begin(); dIt != ddIt->end(); dIt++)
		{
			std::cout << *dIt;
			if (dIt + 1 != ddIt->end())
				std::cout << ", ";
		}
		std::cout << "] ";
	}
	std::cout << '\n';
}

void	PmergeMe::insert()
{
	deqOfDeq arr;

	arr = makePair();
	std::cout << "maindeq: ";print(arr);
	creatMainChainPend(arr);
	printpendChain();
	inserting();
	copyToMainDeq(mainChain);
	mainChain.clear();
	cof /= 2;
}

void	PmergeMe::recursion()
{
	deqOfDeq arr;

	std::cout << "\ndept: " << ++nbr << '\n';
	if (nbr != 0)
		cof *= 2;
	arr = makePair();
	sorting(arr);
	copyToMainDeq(arr);
	if (continueRec(arr))
		recursion();
	insert();
}