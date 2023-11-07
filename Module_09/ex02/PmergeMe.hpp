/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 07:50:33 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/11/06 11:30:42 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <deque>
#include <list>
#include <sstream>

typedef std::deque< std::pair< std::deque<int>, std::deque<int> > > dequeOfPairsOfDeque;
typedef std::pair< std::deque<int>, std::deque<int> > pairOfDeque;
typedef std::deque< std::deque<int> > dequeOfDeque;
typedef	std::deque<int> deque;

class PmergeMe
{
	private:
		dequeOfPairsOfDeque				mainPairs;
		dequeOfPairsOfDeque				copyOfPairs;
		dequeOfPairsOfDeque::iterator	dpdIt;
		dequeOfDeque							deqOfSplitedPair;
		dequeOfDeque							copyOfSplitedPair;
		dequeOfDeque							pending;
		dequeOfDeque					NbrsOfDeq;
		dequeOfDeque::iterator			ddIt;
		dequeOfDeque::iterator			pIt;
		dequeOfDeque::iterator			sIt;
		dequeOfDeque::iterator			sIt2;
		pairOfDeque						simplePair;
		pairOfDeque						splitedPair;
		deque							FirstOfSimplePair;
		deque							SecondOfSimplePair;
		deque							sortedNbrsOfDeq;
		deque							TmpOfDeq;
		deque::iterator					dIt;
		std::string 					str;
		int								nbr;

		PmergeMe();
		void	recursion();
		void	checkAndStock();
	public:
		PmergeMe(char **av);
		PmergeMe(const PmergeMe &mer);
		PmergeMe &operator=(const PmergeMe &mer);
		~PmergeMe();
		void	print(int x);
		void	print(pairOfDeque tmpSimplePair);
		std::deque< std::deque<int> > getdequeNbrs();
};

std::ostream &operator<<(std::ostream &out, const std::deque<int> &dec);
