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
#include <vector>
#include <list>
#include <sstream>
#include <vector>

typedef std::vector< std::pair< std::vector<int>, std::vector< std::vector<int> >::iterator > > pend;
typedef std::pair< std::vector<int>, std::vector< std::vector<int> >::iterator > pendPair;
typedef std::vector< std::vector<int> > deqOfDeq;
typedef	std::vector<int> vector;

class PmergeMe
{
	private:
		bool				check;
		pend				pend;
		pend::iterator		pIt;
		pend::iterator		pIt2;
		pendPair			pendPair;
		vector				mainDeq;
		deqOfDeq			TmpDeq;
		deqOfDeq			mainChain;
		vector				pair;
		vector				last;
		vector				last2;
		deqOfDeq::iterator	ddIt;
		deqOfDeq::iterator	posIt;
		vector::iterator	dIt;
		std::string 		str;
		size_t				cof;
		int					nbr;
		int					count;
		size_t				nbrPairEqualCof;

		deqOfDeq	makePair();
		void		recursion();
		void		checkAndStock();
		bool		continueRec(deqOfDeq& arr);
		void		inserting(vector deq);
		void		copyToMainDeq(deqOfDeq TmpDeq);
		void		creatMainChainPend(deqOfDeq& arr);
		void		sorting(deqOfDeq& arr);
		void		inserting();
		void		sort_pair_element(vector& temp);
		void		insert();
		void		update_iterator(deqOfDeq::iterator pos);
		void		update_pend(deqOfDeq::iterator it);
	
	public:
		PmergeMe();
		PmergeMe(char **av);
		PmergeMe(const PmergeMe &mer);
		PmergeMe &operator=(const PmergeMe &mer);
		~PmergeMe();
		
		void	print(deqOfDeq mainDeq);
		void	print(vector mainDeq);
		void	printpendChain();
};

std::ostream &operator<<(std::ostream &out, const std::vector<int> &dec);
