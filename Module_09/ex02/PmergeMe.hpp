/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 07:50:33 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/11/01 11:54:26 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <deque>
#include <list>
#include <sstream>

typedef std::deque< std::pair< std::deque<int>, std::deque<int> > > pairsOfDeque;
typedef std::deque< std::deque<int> > dequeOfDeque;


class PmergeMe
{
	private:
		std::deque<int>			rest;
		std::deque<int>			copyFirst;
		std::deque<int>			copySecond;
		std::deque<int>			tmpDeque;
		std::string 			str;
		pairsOfDeque			pair;
		std::pair<std::deque<int>, std::deque<int> > stock;
		pairsOfDeque::iterator	pit;
		dequeOfDeque			dequeNbrs;
		dequeOfDeque::iterator	it;
		int						nbr;
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
