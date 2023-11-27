/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 07:50:27 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/11/27 11:12:42 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int count = 0;

void	PmergeMe::print(vecOfVec mainVec)
{
	for (ddIt = mainVec.begin(); ddIt != mainVec.end(); ddIt++)
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
void	PmergeMe::print(listOfList mainVec)
{
	for (llIt = mainVec.begin(); llIt != mainVec.end(); llIt++)
	{
		std::cout << "[";
		for (lIt = llIt->begin(); lIt != llIt->end(); lIt++)
		{
			std::cout << *lIt;
				std::cout << ", ";
		}
		std::cout << "] ";
	}
	std::cout << '\n';
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

PmergeMe::PmergeMe(){}

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

void	PmergeMe::print(vector mainVec)
{
	std::cout << "[";
	for (dIt = mainVec.begin(); dIt != mainVec.end(); dIt++)
	{
			std::cout << *dIt;
			if (dIt + 1 != mainVec.end())
				std::cout << ", ";
	}
	std::cout << "] ";
}
void	PmergeMe::print(list mainVec)
{
	// std::cout << "size: " << mainLst.size() << '\n';
	std::cout << "[";
	for (lIt = mainVec.begin(); lIt != mainVec.end(); lIt++)
	{
		std::cout << *lIt << ' ';
	}
	std::cout << "] ";
}

void	PmergeMe::checkAndStock()
{
	if (!std::isdigit(str.front()))
		throw (std::invalid_argument("Error: invalid argument"));

	std::stringstream ss;

	ss << str;
	ss >> nbr;
	if (std::find(mainVec.begin(), mainVec.end(), nbr) != mainVec.end())
		throw (std::invalid_argument("Error: no duplicated numbers"));
	mainVec.push_back(nbr);
	mainLst.push_back(nbr);
}

PmergeMe::PmergeMe(char **av)
{
	for (int i = 1; av[i]; i++)
	{
		str = static_cast<std::string>(av[i]);
		PmergeMe::checkAndStock();
	}
	if (mainVec.size() == 1)
		return ;
	
	std::cout << "before: ";print(mainVec);
	size_t x = mainVec.size();

	nbr = -1;
	cof = 1;
	PmergeMe::recursionVec();

	std::cout << "\n\naftervector: ";print(mainVec);
	if (x == mainVec.size() && std::is_sorted(mainVec.begin(), mainVec.end()))
		std::cout << "\nsorted\n";
	else
		std::cout << "not\n";
	std::cout  << "\ncomparison --> " << count << std::endl;
		
	nbr = -1;
	count = 0;
	cof = 1;
	std::cout << "\nbeforelist: ";print(mainLst);
	PmergeMe::recursionList();
	
	std::cout << "\n\nafterlist: ";print(mainLst);
	if (x == mainLst.size() && std::is_sorted(mainLst.begin(), mainLst.end()))
		std::cout << "\nsorted\n";
	else
		std::cout << "not\n";
	std::cout  << "\ncomparison --> " << count << std::endl;
}

//##############@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@########################
//         vector

bool	comp(vector a, vector b)
{
	++count;
	return (a.back() <= b.back());
}

bool	PmergeMe::continueRec(vecOfVec& vec)
{
	ddIt = vec.begin();
	if (ddIt->size() == cof && (ddIt + 1)->size() == cof)
		ddIt += 2;
	while (ddIt != vec.end())
	{
		if (ddIt->size() == cof && (ddIt + 1)->size() == cof)
			return true;
		++ddIt;
	}
	return (false);
}

vecOfVec	PmergeMe::makePair()
{
	vecOfVec 	vec;
	vector 		tempVec;

	dIt = mainVec.begin();
	while (dIt != mainVec.end())
	{
		for (size_t i = 0; i < cof; ++i)
		{
			if (dIt == mainVec.end())
				break;
			tempVec.push_back(*dIt);
			++dIt;
		}
		vec.push_back(tempVec);
		tempVec.clear();
	}
	return (vec);
}

void	PmergeMe::copyToMainVec(vecOfVec tmpVec)
{
	mainVec.clear();
	for (ddIt = tmpVec.begin(); ddIt != tmpVec.end(); ++ddIt)
		std::copy(ddIt->begin(), ddIt->end(), std::inserter(mainVec, mainVec.end()));
}

void	PmergeMe::stockLast(vecOfVec& vec)
{
	if (vec.back().size() != cof)
	{
		last = vec.back();
		vec.pop_back();
	}
}

void	PmergeMe::creatMainChainPend(vecOfVec& vec)
{
	stockLast(vec);
	pend.clear();
	pend.reserve(mainVec.size());
	mainChain.reserve(mainVec.size());
	mainChain.clear();
	mainChain.push_back(*vec.begin());
	mainChain.push_back(*(vec.begin() + 1));
	for (ddIt = vec.begin() + 2; ddIt != vec.end();)
	{
		pendPair.second = mainChain.end();
		pendPair.first = *ddIt;
		++ddIt;
		if (ddIt != vec.end())
			pendPair.second = mainChain.insert(mainChain.end(), *ddIt);
		pend.push_back(pendPair);
		pendPair.first.clear();
		if (ddIt != vec.end())
			++ddIt;
	}
}

void	PmergeMe::sorting(vecOfVec& vec)
{
	for (ddIt = vec.begin(); ddIt != vec.end(); ++ddIt)
	{
		++count;
		if ((ddIt + 1) == vec.end() || ddIt->size() != (ddIt + 1)->size())
			break;
		if (ddIt->back() > (ddIt + 1)->back())
			std::swap(*ddIt, *(ddIt + 1));
		++ddIt;
	}
}

void	PmergeMe::inserting()
{
	pend::iterator it;
	int	idx;
	long int jacob[] ={2, 2, 6, 10, 22, 42, 86, 170, 342, 682, 1366, 2730, 5462, 10922, 21846, 43690, 87382, 174762, 349526, 699050, 1398102, 2796202, 5592406, 11184810,
						22369622, 44739242, 89478486, 178956970, 357913942, 715827882, 1431655766, 2863311530, 5726623062, 11453246122, 22906492246, 45812984490};
	idx = 0;
	while (pend.size())
	{
		end = pend.begin();
		begin = pend.begin();
		for (int i = 0; i < jacob[idx] - 1 && begin != pend.end(); ++i)
			++begin;
		if (begin == pend.end())
			--begin;
		while (true)
		{
			pos = std::lower_bound(mainChain.begin(), begin->second, begin->first, comp);
			pos = mainChain.insert(pos, begin->first);
			pend.erase(begin);
			for (it = pend.begin(); it != pend.end(); ++it)
			if (it->second >= pos) 
				++it->second;
			if (begin == end)
				break ;
			--begin;
		}
		++idx;
	}
	if (last.size())
	{
		mainChain.push_back(last);
		last.clear();
	}
}

void	PmergeMe::recursionVec()
{
	vecOfVec vec;

	if (++nbr != 0)
		cof *= 2;
	vec = makePair();
	sorting(vec);
	copyToMainVec(vec);
	if (continueRec(vec))
		recursionVec();
	vec.clear();
	vec = makePair();
	creatMainChainPend(vec);
	inserting();
	copyToMainVec(mainChain);
	cof /= 2;
}

//##############@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@########################
//         LIST

listOfList	PmergeMe::makePairList()
{
	listOfList 	lst;
	list 		tmpLst;

	lIt = mainLst.begin();
	while (lIt != mainLst.end())
	{
		for (size_t i = 0; i < cof; ++i)
		{
			if (lIt == mainLst.end())
				break;
			tmpLst.push_back(*lIt);
			++lIt;
		}
		lst.push_back(tmpLst);
		tmpLst.clear();
	}
	return (lst);
}

void	PmergeMe::sorting(listOfList& lst)
{
	listOfList::iterator	nextP;
	listOfList::iterator	pos;

	pos = lst.begin();
	nextP = lst.begin();
	std::advance(nextP, 1);
	for (size_t i = 0; i < lst.size() - 1; i += 2)
	{
		++count;
		if (nextP == lst.end() || pos->size() != nextP->size())
			break;
		if (pos->back() > nextP->back())
			std::swap(*pos, *nextP);
		std::advance(pos, 2);
		std::advance(nextP, 2);
	}
	
}

void	PmergeMe::copyToMainLst(listOfList tmpLst)
{
	mainLst.clear();
	for (llIt = tmpLst.begin(); llIt != tmpLst.end(); std::advance(llIt, 1))
		std::copy(llIt->begin(), llIt->end(), std::inserter(mainLst, mainLst.end()));
}

bool	PmergeMe::continueRec(listOfList &lst)
{
	llIt = lst.begin();
	if (llIt->size() == cof)
		++llIt;
	if (llIt->size() == cof)
		++llIt;
	while (llIt != lst.end())
	{
		if (llIt->size() == cof)
		{
			++llIt;
			if (llIt != lst.end())
				if (llIt->size() == cof)
					return true;
		}
		++llIt;
	}
	return (false);
}

void	PmergeMe::stockLast(listOfList &lst)
{
	if (lst.back().size() != cof)
	{
		lastInList = lst.back();
		lst.pop_back();
	}
}

void	PmergeMe::creatMainChainPend(listOfList &lst)
{
	stockLast(lst);
	pendList.clear();
	mainChainL.clear();
	mainChainL.push_back(*lst.begin());
	mainChainL.pop_front();
	mainChainL.push_back(*lst.begin());
	mainChainL.pop_front();
	while (!lst.empty())
	{
		pendPairL.first = lst.front();
		pendPairL.second = mainChainL.end();
		lst.pop_front();
		if (!lst.empty())
			pendPairL.second = mainChainL.insert(mainChainL.end(), lst.front());
		pendList.push_back(pendPairL);
		pendPairL.first.clear();
		if (!lst.empty())
			lst.pop_front();
	}
}

bool	compL(list a, list b)
{
	++count;
	return (a.back() <= b.back());
}

void	PmergeMe::insertingList()
{
	pendList::iterator it;
	int	idx;
	long int jacob[] ={2, 2, 6, 10, 22, 42, 86, 170, 342, 682, 1366, 2730, 5462, 10922, 21846, 43690, 87382, 174762, 349526, 699050, 1398102, 2796202, 5592406, 11184810,
						22369622, 44739242, 89478486, 178956970, 357913942, 715827882, 1431655766, 2863311530, 5726623062, 11453246122, 22906492246, 45812984490};
	idx = 0;
	while (pendList.size())
	{
		endL = pendList.begin();
		beginL = pendList.begin();
		for (int i = 0; i < jacob[idx] - 1 && beginL != pendList.end(); ++i)
			++beginL;
		if (beginL == pendList.end())
			--beginL;
		while (true)
		{
			posL = std::lower_bound(mainChainL.begin(), beginL->second, beginL->first, compL);
			posL = mainChainL.insert(posL, beginL->first);
			pendList.erase(beginL);
			if (beginL == endL)
				break ;
			--beginL;
		}
		++idx;
	}
	if (lastInList.size())
	{
		mainChainL.push_back(lastInList);
		lastInList.clear();
	}
}

void	PmergeMe::recursionList()
{
	listOfList lst;

	if (++nbr != 0)
		cof *= 2;
	lst = makePairList();
	sorting(lst);
	copyToMainLst(lst);
	if (continueRec(lst))
		recursionList();
	lst.clear();
	lst = makePairList();
	creatMainChainPend(lst);
	insertingList();
	copyToMainLst(mainChainL);
	cof /= 2;
}