/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 07:50:27 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/11/14 09:53:40 by zouaraqa         ###   ########.fr       */
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
	for (ddIt = mainDeq.begin(); ddIt != mainDeq.end(); ddIt++)
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

bool	PmergeMe::check_all_cof()
{
	nbrPairEqualCof = 0;
	for (ddIt = mainDeq.begin(); ddIt != mainDeq.end(); ddIt++)
	{
		if (ddIt->size() == cof)
			nbrPairEqualCof++;
	}
	if (nbrPairEqualCof == mainDeq.size())
		return (true);
	return (false);
}

void	PmergeMe::inserting(deque deq)
{
	for (ddIt = mainDeq.begin(); ddIt != mainDeq.end(); ddIt++)
	{
		count++;
		if (deq.back() < ddIt->back() && ddIt == mainDeq.begin())
		{
			mainDeq.insert(ddIt, deq);
			break ;
		}
		if ((ddIt + 1) != mainDeq.end() && deq.back() > ddIt->back() && deq.back() < (ddIt + 1)->back())
		{
			mainDeq.insert(ddIt + 1, deq);
			break ;
		}
		if (deq.back() > ddIt->back() && ddIt + 1 == mainDeq.end())
		{
			mainDeq.insert(ddIt + 1, deq);
			break ;
		}
	}
}


//#####################################----------------------------------##########
void	PmergeMe::recursion()
{
	pendPair	pendPair;
	pend		pend;
	deqOfDeq	pending;
	deque		restDeq;
	size_t		i;

	nbr++;
	if (nbr != 0)
		cof *= 2;

	//print
	std::cout << "dept; 		 " << nbr  << "  cof: " << cof<< '\n';
	std::cout << "befor swap :     ";
	print(mainDeq);

	//############ STORE LAST ONE IN REST
	if (!check_all_cof())
	{
		restDeq = mainDeq.back();
		mainDeq.pop_back();

		//print
		printRest(restDeq, dIt);
	}
	if (mainDeq.size() % 2 != 0)
	{
		restDeq = mainDeq.back();
		mainDeq.pop_back();

		//print
		printRest(restDeq, dIt);
	}

	//############ SORT
	for (ddIt = mainDeq.begin(); ddIt != mainDeq.end(); ddIt += 2)
	{
		count++;
		if (ddIt->back() > (ddIt + 1)->back())
			std::swap(*ddIt, *(ddIt + 1));
	}
	std::cout << "after swap :     ";
	print(mainDeq);
	
	
	//############ CHECK IF ONLY 2 deq = COF (IT MEANS WE HAVE ONE PAIR)
	if (check_cof())
	{
		if (!restDeq.empty())
			mainDeq.push_back(restDeq);
		return ;
	}
		
		
	//############ CREATE PAIRS
	for (ddIt = mainDeq.begin(); ddIt != mainDeq.end(); ddIt += 2)
	{
		//push the first and second of mainDeq in pair then push the pair to tmp
		for (dIt = ddIt->begin(); dIt != ddIt->end(); dIt++)
			pair.push_back(*dIt);
		for (dIt = (ddIt + 1)->begin(); dIt != (ddIt + 1)->end(); dIt++)
			pair.push_back(*dIt);
		TmpOfDeq.insert(TmpOfDeq.end(), pair);
		pair.clear();
	}
	mainDeq = TmpOfDeq;
	TmpOfDeq.clear();

	//print
	std::cout << "after :          ";
	print(mainDeq);
	if (!restDeq.empty())
		mainDeq.push_back(restDeq);
	std::cout << "afterinsert rest:";
	print(mainDeq);
	std::cout << "\n----------------------------------\n";

	//############ rec
	recursion();
	// std::cout << "\n----------------------------------\n";
//----------------------------------------

	cof /= 2;
	
	//print
	std::cout << "\nback from " << nbr-- << "\n";
	std::cout << "size cof: " << cof << '\n' << "NOW WE GOnNA SPLIT TO PAIRS \n\n";
	
	std::cout << "maindeq:     ";
	print(mainDeq);
	while(1);

	//############ SPLITING into two pairs
	for (ddIt = mainDeq.begin(); ddIt != mainDeq.end(); ddIt++)
	{
		i = -1;
		dIt = ddIt->begin();
		for (; dIt != ddIt->end(); dIt++)
		{
			if (++i == cof)//copy first pair
				break ;
			pair.push_back(*dIt);
		}
		// TmpOfDeq.push_back(pair);
		deqOfDeq::iterator it = TmpOfDeq.insert(TmpOfDeq.end(), pair);
		pendPair.first.push_back(pair);
		pendPair.second = it;
		pend.push_back(pendPair);
		pendPair.first.clear();
		pair.clear();
		for (; dIt != ddIt->end(); dIt++)
		{
			pair.push_back(*dIt);
			if (++i == (cof * 2))//copy second pair
				break ;
		}
		it = TmpOfDeq.insert(TmpOfDeq.end(), pair);
		pendPair.first.push_back(pair);
		pendPair.second = it;
		pend.push_back(pendPair);
		pendPair.first.clear();
		// std::cout << "deq: >> " << pend.back().first.back() << "  " << *pend.back().second << '\n';
		// TmpOfDeq.push_back(pair);
		pair.clear();
	}
	mainDeq = TmpOfDeq;
	TmpOfDeq.clear();

	//print
	std::cout << "splited:      ";
	print(mainDeq);
	printRest(restDeq, dIt);
	
	//############ STOCK IN PENDING
	//COPY FIRST 2 PAIR IN TMP AND POP THEM FROM MAIN
	for (int i = 0; i < 2; i++)
	{
		TmpOfDeq.push_back(mainDeq.front());
		mainDeq.pop_front();
		pend.erase(pend.begin());
	}
	
	//print pend
	for (pend::iterator pit = pend.begin(); pit != pend.end(); pit++)
	{
		for (ddIt = pit->first.begin(); ddIt != pit->first.end(); ddIt++)
			std::cout << *ddIt << ' ';
		
		std::cout << ',';
	}
		std::cout << '\n';
		std::cout << '\n';
	// while (1);
	int x = -1;
	for (ddIt = mainDeq.begin(); ddIt != mainDeq.end(); ddIt++)
	{
		if (++x % 2 == 0)
			continue;
			// pending.push_back(*ddIt);
		else
			TmpOfDeq.push_back(*ddIt);
	}
	mainDeq = TmpOfDeq;
	TmpOfDeq.clear();
	
	if (!restDeq.empty())
		pending.push_back(restDeq);

	//print
	std::cout << "pending:       ";
	print(pending);
	std::cout << "mainPair:      ";
	print(mainDeq);
	
	//############### INSERT
	x = -1;

	for (pend::iterator pit = pend.begin(); pit != pend.end(); pit++)
	{
		if (++x % 2 != 0 /*&& pit +1 != pend.end()*/)
		{
	// std::cout << " pit " << pit->first.front() << '\n';
			pend.erase(pit);
			pit = pend.begin();
		}
			// if (pit == pend.end())
			// 	break ;
	// std::cout << " in " << x << '\n';
		
	}
	std::cout <<x<< " after erase:                                             ";
	for (pend::iterator pit = pend.begin(); pit != pend.end(); pit++)
	{
		for (ddIt = pit->first.begin(); ddIt != pit->first.end(); ddIt++)
			std::cout << *ddIt << ' ';

		std::cout << ',';
	}
		std::cout << '\n';
	if (!pending.empty())
		for (pddIt = pending.begin(); pddIt != pending.end(); pddIt++)
			inserting(*pddIt);
	
	//print
	std::cout << "finalPair:     ";
	print(mainDeq);
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
	pair.push_back(nbr);
	mainDeq.push_back(pair);
	pair.clear();
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
	// for (ddIt = mainDeq.begin(); ddIt != mainDeq.end(); ddIt++)
	// {
	// 	deqOfDeq::iterator it = TmpOfDeq.insert(TmpOfDeq.begin(), *ddIt);
	// }

	// if (mainDeq.size() % 2 != 0)
	// {
	// 	last = mainDeq.back();
	// 	mainDeq.pop_back();
	// }
	

	//PRINT
	std::cout << "after stock last:     ";
	print(mainDeq);

	nbr = -1;
	cof = 1;
	count = 0;
	std::cout << "\n-----------------------\n";
	//########## REC
	PmergeMe::recursion();
	
	std::cout << "\n------------####### SORTED I GUESS ########-----------\n\n";

	if (!last.empty())
		inserting(last);
// while
	//print
	print(mainDeq);
	std::cout << '\n';
	std::cout << "count:  " <<  count << '\n';
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
