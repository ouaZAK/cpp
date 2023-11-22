/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 07:50:33 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/11/22 10:43:01 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <deque>
#include <list>
#include <sstream>
#include <vector>

typedef std::deque< std::pair< std::deque<int>, std::deque< std::deque<int> >::iterator > > pend;
typedef std::pair< std::deque<int>, std::deque< std::deque<int> >::iterator > pendPair;
typedef std::deque< std::deque<int> > deqOfDeq;
typedef	std::deque<int> deque;

class PmergeMe
{
	private:
		pend					pend;
		pend::iterator			pIt;
		pend::iterator			pIt2;
		pendPair				pendPair;
		deque					mainDeq;
		deqOfDeq				TmpDeq;
		deqOfDeq				mainChain;
		deque					pair;
		deque					last;
		deque					last2;
		deqOfDeq::iterator		ddIt;
		deqOfDeq::iterator		posIt;
		deque::iterator			dIt;
		std::string 			str;
		size_t					cof;
		int						nbr;
		int						count;
		size_t					nbrPairEqualCof;

		PmergeMe();
		void	recursion();
		void	checkAndStock();
		bool	continueRec(deqOfDeq& arr);
		void	inserting(deque deq);
		void	copyToMainDeq(deqOfDeq TmpDeq);
		void	creatMainChainPend(deqOfDeq& arr);
		void	sorting(deqOfDeq& arr);
		void	inserting();
		
		deqOfDeq	makePair();
		void		sort_pair_element(deque& temp);
		void		insert();
		void		update_iterator(deqOfDeq::iterator pos);
	
		void	update_pend(deqOfDeq::iterator it);
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
