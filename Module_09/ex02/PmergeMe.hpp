/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 07:50:33 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/11/15 17:22:01 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <deque>
#include <list>
#include <sstream>


typedef std::deque< std::pair< std::deque<int>, std::deque< std::deque<int> >::iterator > > pend;
typedef std::pair< std::deque<int>, std::deque< std::deque<int> >::iterator > pendPair;
typedef std::deque< std::deque<int> > deqOfDeq;
typedef	std::deque<int> deque;

class PmergeMe
{
	private:
		pend					pend;
		pend::iterator			pIt;
		pendPair				pendPair;
		deque					mainDeq;
		deqOfDeq				TmpDeq;
		deqOfDeq				mainChain;
		deque					pair;
		deque					last;
		deque					last2;
		deqOfDeq::iterator		ddIt;
		deqOfDeq::iterator		ddItComp;
		deque::iterator			dIt;
		std::string 			str;
		size_t					cof;
		int						nbr;
		int						count;
		size_t					nbrPairEqualCof;

		PmergeMe();
		void	recursion();
		void	checkAndStock();
		bool	check_cof();
		void	inserting(deque deq);
		void	makePair();
		void	copyToMainDeq(deqOfDeq TmpDeq);
		void	creatMainChainPend();
	public:
		PmergeMe(char **av);
		PmergeMe(const PmergeMe &mer);
		PmergeMe &operator=(const PmergeMe &mer);
		~PmergeMe();
		void	print(deqOfDeq mainDeq);
		void	print(deque mainDeq);
void printpendChain();
};

std::ostream &operator<<(std::ostream &out, const std::deque<int> &dec);
