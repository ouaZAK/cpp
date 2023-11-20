/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 07:50:27 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/11/20 15:12:16 by zouaraqa         ###   ########.fr       */
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
	{
		std::cout << *ddIt << ' ';
	}
	// std::cout << '\n';
	
	std::cout << "\npend :      >> " ;
	if (!pend.empty())
	{
		for (pend::iterator it = pend.begin(); it != pend.end(); it++)
		{
			// std::cout << ++i << '\n';
			for (dIt = it->first.begin(); dIt != it->first.end(); dIt++)
			{
			// std::cout << i++ << '\n';
				
				std::cout << *dIt;
			}
			std::cout << ' ';
		}
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

bool	PmergeMe::continueRec()
{
	ddIt = TmpDeq.begin();
	//we have 2 elem with the ssame size of cof
	if (ddIt->size() == cof && (ddIt + 1)->size() == cof)
		ddIt += 2;
	while (ddIt != TmpDeq.end())
	{
		//if there is more than 2 elem with the same size of cof continu rec
		if (ddIt->size() == cof && (ddIt + 1)->size() == cof)
			return true;
		++ddIt;
	}
	return (false);
}

void	PmergeMe::makePair()
{
	TmpDeq.clear();
	dIt = mainDeq.begin();
	
	while (dIt != mainDeq.end())
	{
		for (size_t i = 0; i < cof && dIt != mainDeq.end(); i++)
		{
			pair.push_back(*dIt);
			++dIt;
		}
		TmpDeq.push_back(pair);
		pair.clear();
	}
}

void	PmergeMe::copyToMainDeq(deqOfDeq TmpDeq)
{
	mainDeq.clear();
	for (ddIt = TmpDeq.begin(); ddIt != TmpDeq.end(); ddIt++)
		for (dIt = ddIt->begin(); dIt != ddIt->end(); dIt++)
			mainDeq.push_back(*dIt);
	TmpDeq.clear();
}

void	PmergeMe::creatMainChainPend()
{
	//if last elem is not the size of cof we stock it in last so after we can insert it in mainchain
	if (TmpDeq.back().size() != cof)
	{
		last = TmpDeq.back();
		TmpDeq.pop_back();
	}
	mainChain.clear();
	pend.clear();
	// mainChain.resize(TmpDeq.size());
	// pend.resize(TmpDeq.size());
	mainChain.push_back(TmpDeq.at(0));
	mainChain.push_back(TmpDeq.at(1));
	ddIt = TmpDeq.begin() + 2;
	while (ddIt != TmpDeq.end())
	{
		pendPair.second = mainChain.end();
		pendPair.first = (*ddIt);
		++ddIt;
		if (!ddIt->empty())
			pendPair.second = mainChain.insert(mainChain.end(), *ddIt);
		pend.push_back(pendPair);
		pendPair.first.clear();
		// we protect so we dont skip the tmpdeq.end() and stuck in loop infini
		if (ddIt != TmpDeq.end())
			++ddIt;
	}
}

void	PmergeMe::sorting()
{
	//####### sort pairs with only size 2
	for (ddIt = TmpDeq.begin(); ddIt != TmpDeq.end(); ddIt++)
		if (ddIt->size() == 2)
		{
		count++;
			if (ddIt->front() > (ddIt)->back())
				std::swap(ddIt->front(), ddIt->back());
		}
	
//print
std::cout << "sorted: ";
print(TmpDeq);

	//####### sort pairs
	for (ddIt = TmpDeq.begin(); ddIt != TmpDeq.end(); ddIt++)
	{
		count++;
		if ((ddIt + 1) == TmpDeq.end() || ddIt->size() != (ddIt + 1)->size())
			break;
		if (ddIt->back() > (ddIt + 1)->back())
			std::swap(*ddIt, *(ddIt + 1));
		ddIt++;
	}
}

void	PmergeMe::inserting()
{
	//####### inserting in mainchain
	for (pIt = pend.begin(); pIt != pend.end(); pIt++)
	{
		
		if (pIt->second > mainChain.end())
			pIt->second = mainChain.end();
		// std::cout << *pIt->second << '\n';
		ddIt = std::lower_bound(mainChain.begin(), pIt->second, pIt->first, &comp);
		posIt = mainChain.insert(ddIt, pIt->first);
		// pend.pop_front();
		//if the second iterator we inserted is bigger than other it in the pend we must increment them by one because the position where we inserted is now decalat b w7da
		for (pIt2 = pend.begin(); pIt2 != pend.end(); pIt2++)
		{
			if (pIt2->second >= posIt)
			{
				if (pIt2->second != mainChain.end())
					++pIt2->second;
					// pIt2->second = mainChain.end();
			}
		}
	}

	pend.clear();
}

//#####################################----------------------------------##########
void	PmergeMe::recursion()
{
	std::cout << "\ndept: " << ++nbr << '\n';
	if (nbr != 0)
		cof *= 2;

	//####### make pairs
	makePair();
	
//print
std::cout << "tmpBEF: ";print(TmpDeq);


	//###### sort
	sorting();


//print	
std::cout << "sorted: ";print(TmpDeq);
	
	
	//####### copy to maindeq
	copyToMainDeq(TmpDeq);
	

//print
std::cout << "maindeq: ";print(mainDeq);

	//check if there is more than 2 pairs with same size of cof continue the rec
	if (continueRec())
		recursion();
	//---------------------------------------------------REC

	std::cout << "//---------------------------------------------------//\n\n";
	
	std::cout << "\nback from " << nbr-- << "\n";
	std::cout << "size cof: " << cof << '\n' << "NOW WE GOnNA SPLIT TO PAIRS \n\n";
	
	//####### make pairs
	makePair();
	
	//####### create main cheain and pend
	creatMainChainPend();


// print
std::cout << "------befor insert: ";printpendChain();

	//######### inserting
	inserting();


	if (!last.empty())
	{
		mainChain.push_back(last);
		last.clear();
	}


// print
std::cout << "-----after insert: ";printpendChain();


	//###### copy to maindeq
	copyToMainDeq(mainChain);
	mainChain.clear();
	cof /= 2;
}
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
	std::cout << '\n';
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
//#################
