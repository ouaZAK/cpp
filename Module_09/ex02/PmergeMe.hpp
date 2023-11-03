/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 07:50:33 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/11/03 11:53:15 by zouaraqa         ###   ########.fr       */
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
		dequeOfDeque					NbrsOfDeq;
		dequeOfDeque::iterator			ddIt;
		pairOfDeque						simplePair;
		pairOfDeque						tmpSimplePair;
		deque							RestOfDeq;
		deque							FirstOfSimplePair;
		deque							SecondOfSimplePair;
		deque							TmpOfDeq;
		deque::iterator					dit;
		std::string 					str;
		int								nbr;
		PmergeMe();
	public:
		PmergeMe(char **av);
		PmergeMe(const PmergeMe &mer);
		PmergeMe &operator=(const PmergeMe &mer);
		~PmergeMe();
		void	checkAndStock();
		void	recursion();
		void	print();
		void	print2();
		std::deque< std::deque<int> > getdequeNbrs();
};

std::ostream &operator<<(std::ostream &out, const std::deque<int> &dec);
