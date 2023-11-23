/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 07:50:33 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/11/23 15:27:39 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <sstream>
#include <vector>
#include <deque>
#include <list>

typedef std::vector< std::pair< std::vector<int>, std::vector< std::vector<int> >::iterator > > pend;
typedef std::pair< std::vector<int>, std::vector< std::vector<int> >::iterator > pendPair;
typedef std::vector< std::vector<int> > vecOfVec;
typedef	std::vector<int> vector;

class PmergeMe
{
	private:
		vector				mainDeq;
		vecOfVec			mainChain;
		pend				pend;
		pend::iterator		pIt;
		pendPair			pendPair;
		vector				last;
		vecOfVec::iterator	ddIt;
		vector::iterator	dIt;
		std::string 		str;
		size_t				cof;
		int					nbr;

		vecOfVec	makePair();
		void		recursion();
		void		checkAndStock();
		bool		continueRec(vecOfVec& arr);
		void		copyToMainDeq(vecOfVec TmpDeq);
		void		creatMainChainPend(vecOfVec& arr);
		void		sorting(vecOfVec& arr);
		void		inserting();
		void		sort_pair_element(vector& temp);
		void		insert();
		void		update_iterator(vecOfVec::iterator pos);
	
	public:
		PmergeMe();
		PmergeMe(char **av);
		PmergeMe(const PmergeMe &mer);
		PmergeMe &operator=(const PmergeMe &mer);
		~PmergeMe();
		
		void	print(vecOfVec mainDeq);
		void	print(vector mainDeq);
		void	printpendChain();
};

std::ostream &operator<<(std::ostream &out, const std::vector<int> &dec);
