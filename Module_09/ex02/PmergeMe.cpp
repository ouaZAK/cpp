/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 07:50:27 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/11/14 12:31:26 by zouaraqa         ###   ########.fr       */
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

PmergeMe::PmergeMe()
{
}

bool	PmergeMe::check_cof()
{
	std::cout << "size:  ";
	nbrPairEqualCof = 0;
	for (ddIt = TmpDeq.begin(); ddIt != TmpDeq.end(); ddIt++)
	{
		if (ddIt->size() == cof)
		{
			std::cout << ddIt->size() << ' ';
			nbrPairEqualCof++;
		}
		if (nbrPairEqualCof > 2)
		{
	std::cout << '\n';
			return (false);
		}
	}
	std::cout << '\n';
	return (true);
}

void	PmergeMe::makePair()
{
	size_t i;
	
	i = 0;
	std::cout << "cof: " << cof << '\n';
	for (dIt = mainDeq.begin(); dIt != mainDeq.end(); dIt++)
	{
	// std::cout << "bef " << i << '\n';
	// std::cout << *dIt << '\n';
		if (i++ == cof)
		{
			TmpDeq.push_back(pair);
			pair.clear();
			i = 1;
		}
	// std::cout << *dIt << '\n';
	// std::cout << "aft " << i << '\n';
		pair.push_back(*dIt);
		if (dIt + 1 == mainDeq.end())
		{
			TmpDeq.push_back(pair);
			pair.clear();
		}
	}

	//print
std::cout << "tmpBEF: ";
print(TmpDeq);
	
	if (TmpDeq.size() % 2 != 0)
	{
		last2 = TmpDeq.back();
		TmpDeq.pop_back();
//print
std::cout << "tmpAFT: ";
print(TmpDeq);
	}
}

void	PmergeMe::copyToMainDeq()
{
	mainDeq.clear();
	for (ddIt = TmpDeq.begin(); ddIt != TmpDeq.end(); ddIt++)
		for (dIt = ddIt->begin(); dIt != ddIt->end(); dIt++)
			mainDeq.push_back(*dIt);
}

void	PmergeMe::creatMainChainPend()
{
	
}


//#####################################----------------------------------##########
void	PmergeMe::recursion()
{
	std::cout << "\ndept: " << ++nbr << '\n';
	if (nbr != 0)
		cof *= 2;
	
	//stock
	if (mainDeq.size() % 2 != 0)
	{
		last.push_back(mainDeq.back());
		mainDeq.pop_back();
//print
std::cout << "last:";
print(last);
	}
	
	//####### make pairs
	makePair();
	

	
	//####### sort pairs
	for (ddIt = TmpDeq.begin(); ddIt != TmpDeq.end(); ddIt += 2)
	{
		count++;
		if (ddIt->back() > (ddIt + 1)->back())
			std::swap(*ddIt, *(ddIt + 1));
	}

	//return stocked to tmp
	if (!last2.empty())
	{
		TmpDeq.push_back(last2);
		last2.clear();
	}

//print		
std::cout << "sorted: ";
print(TmpDeq);
	
	//####### copy to maindeq
	copyToMainDeq();
	
	
	if (!last.empty())
	{
		mainDeq.push_back(last.back());
		last.clear();
	}

//print
std::cout << "maindeq: ";
print(mainDeq);

	if (check_cof())
	{
		TmpDeq.clear();
		return ;
	}
	TmpDeq.clear();
	//---------------------------------------------------REC
	recursion();
	std::cout << "//---------------------------------------------------//\n\n";
	
	cof /= 2;
	std::cout << "\nback from " << nbr-- << "\n";
	std::cout << "size cof: " << cof << '\n' << "NOW WE GOnNA SPLIT TO PAIRS \n\n";
	
	makePair();
	
	creatMainChainPend();
	
	copyToMainDeq();
	TmpDeq.clear();
	


	
//print
std::cout << "maindeq: ";
print(mainDeq);

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

//print
std::cout << "at start:             ";
print(mainDeq);
	
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
// 	//print
// 	print(mainDeq);
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
