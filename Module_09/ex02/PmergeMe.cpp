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

int c = 0;

void	printRest(vector restDeq, vector::iterator dIt)
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

bool	comp(vector a, vector b)
{
	++c;
	return (a.back() <= b.back());
}

PmergeMe::PmergeMe(){}

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

void	PmergeMe::sort_pair_element(vector& temp)
{
	++c;
	if (temp[0] > temp[1])
		std::swap(temp.front(), temp.back());
}

deqOfDeq	PmergeMe::makePair()
{
	deqOfDeq 	arr;
	vector 		temp;

	dIt = mainDeq.begin();
	while (dIt != mainDeq.end())
	{
		for (size_t i = 0; i < cof && dIt != mainDeq.end(); ++i)
		{
			temp.push_back(*dIt);
			++dIt;
		}
		arr.push_back(temp);
		temp.clear();
	}
	return (arr);
}

void	PmergeMe::copyToMainDeq(deqOfDeq TmpDeq)
{
	mainDeq.clear();
	for (ddIt = TmpDeq.begin(); ddIt != TmpDeq.end(); ++ddIt)
		for (dIt = ddIt->begin(); dIt != ddIt->end(); ++dIt)
			mainDeq.push_back(*dIt);
}

void	PmergeMe::creatMainChainPend(deqOfDeq& arr)
{
	deqOfDeq::iterator it;

	if (arr.back().size() != cof)
	{
		last = arr.back();
		arr.pop_back();
	}
	mainChain.clear();
	pend.clear();
	pend.reserve(mainDeq.size());
	mainChain.reserve(mainDeq.size());
	mainChain.push_back(arr[0]);
	mainChain.push_back(arr[1]);
	for (it = arr.begin() + 2; it != arr.end();)
	{
		pendPair.second = mainChain.end();
		pendPair.first = *it;
		++it;
		if (it != arr.end())
			pendPair.second = mainChain.insert(mainChain.end(), *it);
		pend.push_back(pendPair);
		pendPair.first.clear();
		if (it != arr.end())
			++it;
	}
}

void	PmergeMe::sorting(deqOfDeq& arr)
{
	for (ddIt = arr.begin(); ddIt != arr.end(); ++ddIt)
	{
		++c;
		if ((ddIt + 1) == arr.end() || ddIt->size() != (ddIt + 1)->size())
			break;
		if (ddIt->back() > (ddIt + 1)->back())
			std::swap(*ddIt, *(ddIt + 1));
		++ddIt;
	}
}

void	PmergeMe::update_iterator(deqOfDeq::iterator pos)
{
	pend::iterator it;

	for (it = pend.begin(); it != pend.end(); ++it)
	{
		if (it->second >= pos) 
			++it->second;
	}
}

void	PmergeMe::inserting()
{
	deqOfDeq::iterator pos;
	pend::iterator	end;
	pend::iterator	start;
	int	idx;

	long int jcb_stl[] =
	{
        2, 2, 6, 10, 22, 42, 86, 170, 342, 682, 1366,
        2730, 5462, 10922, 21846, 43690, 87382, 174762, 349526, 699050,
        1398102, 2796202, 5592406, 11184810, 22369622, 44739242, 89478486,
        178956970, 357913942, 715827882, 1431655766, 2863311530, 5726623062,
        11453246122, 22906492246, 45812984490
    };
	idx = 0;
	while (pend.size())
	{
		end = pend.begin();
		start = pend.begin();
		for (int i = 0; i < jcb_stl[idx] - 1 && start != pend.end(); ++i)
			++start;
		if (start == pend.end())
			--start;
		while (true)
		{
			pos = std::lower_bound(mainChain.begin(), start->second, start->first, comp);
			pos = mainChain.insert(pos, start->first);
			pend.erase(start);
			update_iterator(pos);
			if (start == end)
				break ;
			--start;
		}
		++idx;
	}
	if (last.size())
	{
		mainChain.push_back(last);
		last.clear();
	}
}

void	PmergeMe::checkAndStock()
{
	std::string::iterator	it;
	vector::iterator		dIt2;

	for (it = str.begin(); it != str.end(); ++it)
		if (!std::isdigit(*it))
			throw (std::invalid_argument("Error: invalid argument"));

	std::stringstream ss;
	ss << str;
	ss >> nbr;
	mainDeq.push_back(nbr);

	for (dIt = mainDeq.begin(); dIt != mainDeq.end(); ++dIt)
		for (dIt2 = dIt + 1; dIt2 != mainDeq.end(); ++dIt2)
			if (*dIt == *dIt2) 
				throw (std::invalid_argument("Error: no duplicated numbers"));
}

PmergeMe::PmergeMe(char **av)
{
	check = false;
	for (int i = 1; av[i]; i++)
	{
		str = static_cast<std::string>(av[i]);
		PmergeMe::checkAndStock();
	}
	if (mainDeq.size() == 1)
		return ;
	size_t x = mainDeq.size();
	nbr = -1;
	cof = 1;
	std::cout << "\n-----------------------\n";

	PmergeMe::recursion();
	std::cout << "\n------------####### SORTED I GUESS ########-----------\n\n";
	if (x == mainDeq.size() && std::is_sorted(mainDeq.begin(), mainDeq.end()))
		std::cout << "sorted\n";
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

PmergeMe::~PmergeMe(){}

std::ostream &operator<<(std::ostream &out, const std::vector<int> &dec)
{
	std::vector<int>::const_iterator cit;
	for (cit = dec.begin(); cit != dec.end(); cit++)
		out << *cit;
	return (out);
}

void	PmergeMe::print(vector mainDeq)
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
	creatMainChainPend(arr);
	inserting();
	copyToMainDeq(mainChain);
	cof /= 2;
	std::cout  << "comparison --> " << c << std::endl;
}

void	PmergeMe::recursion()
{
	deqOfDeq arr;

	if (++nbr != 0)
		cof *= 2;
	arr = makePair();
	sorting(arr);
	copyToMainDeq(arr);
	if (continueRec(arr))
		recursion();
	insert();
}