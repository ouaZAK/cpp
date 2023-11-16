/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 07:50:27 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/11/16 15:48:33 by zouaraqa         ###   ########.fr       */
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
bool	comp(deque d, deque d2)
{
	return (d.back() <= d2.back());
}

PmergeMe::PmergeMe()
{
}

bool	PmergeMe::check_cof()
{
	std::cout << "size:  ";
	ddIt = TmpDeq.begin();
	// print(TmpDeq);
	if (ddIt->size() == cof && (ddIt + 1)->size() == cof)
		ddIt += 2;
	while (ddIt != TmpDeq.end())
	{
		if (ddIt->size() == cof && (ddIt + 1)->size() == cof)
			return true;
		++ddIt;
	}
	return (false);
}

void	PmergeMe::makePair()
{
	size_t i;
	
	TmpDeq.clear();
	for (dIt = mainDeq.begin(); dIt != mainDeq.end();)
	{
		for (i = 0; i < cof && dIt != mainDeq.end(); i++)
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
	//check size of last elem last
	if (TmpDeq.back().size() != cof)
	{
		last = TmpDeq.back();
		TmpDeq.pop_back();
	}
	mainChain.push_back(TmpDeq.at(0));
	mainChain.push_back(TmpDeq.at(1));
	ddIt = TmpDeq.begin();
	ddIt += 2;
	for (; ddIt != TmpDeq.end();)
	{
		pendPair.second = mainChain.end();
		pendPair.first = (*ddIt);
		++ddIt;
		if (!ddIt->empty())
			pendPair.second = mainChain.insert(mainChain.end(), *ddIt);
		pend.push_back(pendPair);
		pendPair.first.clear();
		if (ddIt != TmpDeq.end())
			++ddIt;
	}
}


//#####################################----------------------------------##########
void	PmergeMe::recursion()
{
	std::cout << "\ndept: " << ++nbr << '\n';
	// if (nbr != 0)
		cof *= 2;

	//stock
// 	if (mainDeq.size() % 2 != 0)
// 	{
// 		last.push_back(mainDeq.back());
// 		mainDeq.pop_back();
// //print
// std::cout << "last:";
// print(last);
// 	}
	
	//####### make pairs
	makePair();
	
//print
std::cout << "tmpBEF: ";
print(TmpDeq);
	
	//####### sort pairs
	for (ddIt = TmpDeq.begin(); ddIt != TmpDeq.end(); ddIt++)
	{
		// std::cout << *ddIt << " size : " << ddIt->size() << '\n';	
		if (ddIt->size() == 2)
		{
			if (ddIt->front() > (ddIt)->back())
				std::swap(ddIt->front(), ddIt->back());
		}
	}
	// while(1);

//print
std::cout << "sorted: ";
print(TmpDeq);
	for (ddIt = TmpDeq.begin(); ddIt != TmpDeq.end(); ddIt++)
	{
		// count++;
		if ((ddIt + 1) == TmpDeq.end() || ddIt->size() != (ddIt + 1)->size())
			break;
		if (ddIt->back() > (ddIt + 1)->back())
			std::swap(*ddIt, *(ddIt + 1));
		ddIt++;
	}

	// //return stocked to tmp
	// if (!last2.empty())
	// {
	// 	TmpDeq.push_back(last2);
	// 	last2.clear();
	// }

//print		
std::cout << "sorted: ";
print(TmpDeq);
	
	//####### copy to maindeq
	copyToMainDeq(TmpDeq);
	
	
	// if (!last.empty())
	// {
	// 	mainDeq.push_back(last.back());
	// 	last.clear();
	// }

//print
// std::cout << "maindeq: ";
// print(mainDeq);
	if (check_cof())
		recursion();
	// TmpDeq.clear();
	//---------------------------------------------------REC

	std::cout << "//---------------------------------------------------//\n\n";
	
	cof /= 2;
	std::cout << "\nback from " << nbr-- << "\n";
	std::cout << "size cof: " << cof << '\n' << "NOW WE GOnNA SPLIT TO PAIRS \n\n";
	
	makePair();
	// while (1);

	creatMainChainPend();
	
	//if last rest is ther push it to mainchain
	// if (!last2.empty())
	// {
	// 	mainChain.push_back(last2);
	// 	last2.clear();
	// }

// print
std::cout << "------befor insert: ";
printpendChain();

		for (pIt = pend.begin(); pIt != pend.end(); pIt++)
		{
			ddIt = std::lower_bound(mainChain.begin(), pIt->second, pIt->first, &comp);
			posIt = mainChain.insert(ddIt, pIt->first);
			for (pIt2 = pend.begin(); pIt2 != pend.end(); pIt2++)
			{
				if (pIt2->second >= posIt)
				{
					++pIt2->second;
					if (pIt2->second >= mainChain.end())
						pIt2->second = mainChain.end();
				}
			}			
		}

		// if nbr = -1 dont copy the last at the back
		if (nbr != -1 && !last.empty())
		{
			mainChain.push_back(last);
			last.clear();
		}

// print
std::cout << "-----after insert: ";
	pend.clear();
printpendChain();



	copyToMainDeq(mainChain);
	mainChain.clear();
	TmpDeq.clear();
	


// print
std::cout << "maindeq: ";
// print(mainDeq);
	// while (1);
}
//#####################################----------------------------------##########

void	PmergeMe::checkAndStock()
{
	std::string::iterator it;
	for (it = str.begin(); it != str.end(); it++)
		if (!std::isdigit(*it))
			throw (std::invalid_argument("Error: invalid argument"));
	std::stringstream ss;
	ss << str;
	ss >> nbr;
	mainDeq.push_back(nbr);
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
// print(mainDeq);

	nbr = -1;
	cof = 1;
	count = 0;
	std::cout << "\n-----------------------\n";
	//########## REC
	PmergeMe::recursion();

	std::cout << "\n------------####### SORTED I GUESS ########-----------\n\n";


// 	if (!last.empty())
// 		inserting(last);
// // while
	//print
	print(mainDeq);
// 	std::cout << '\n';
// 	std::cout << "count:  " <<  count << '\n';
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

