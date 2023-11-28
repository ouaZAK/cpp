/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 07:50:33 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/11/28 10:08:30 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <sstream>
#include <vector>
#include <list>
#include <ctime>
#include <iomanip>

typedef std::vector< std::pair< std::vector<int>, std::vector< std::vector<int> >::iterator > > pend;
typedef std::pair< std::vector<int>, std::vector< std::vector<int> >::iterator > pendPair;
typedef std::vector< std::vector<int> > vecOfVec;
typedef	std::vector<int> vector;

typedef	std::list< std::pair< std::list<int>,  std::list< std::list<int> >::iterator > > pendList;
typedef	std::pair< std::list<int>, std::list< std::list<int> >::iterator > pendPairL;
typedef	std::list< std::list<int> > listOfList;
typedef	std::list<int> list;

class PmergeMe
{
	private:
		vector				mainVec;
		vecOfVec			mainChain;
		pend				pend;
		pend::iterator		pIt;
		pendPair			pendPair;
		vector				last;
		vecOfVec::iterator	ddIt;
		vector::iterator	dIt;
		std::string 		str;
		size_t				cof;
		vecOfVec::iterator	pos;
		pend::iterator		begin;
		pend::iterator		end;
		int					nbr;
		int					count;

		double				time;
		std::clock_t		tstart;
		std::clock_t		tend;

		vecOfVec	makePair();
		void		recursionVec();
		void		checkAndStock();
		bool		continueRec(vecOfVec& arr);
		void		copyToMainVec(vecOfVec TmpDeq);
		void		creatMainChainPend(vecOfVec& arr);
		void		sorting(vecOfVec& arr);
		void		inserting();
		void		stockLast(vecOfVec& vec);
		

		list					mainLst;
		listOfList				mainChainL;
		pendList				pendList;
		pendList::iterator		plIt;
		pendPairL				pendPairL;
		list					lastInList;
		listOfList::iterator	llIt;
		list::iterator			lIt;
		listOfList::iterator	posL;
		pendList::iterator		beginL;
		pendList::iterator		endL;

		listOfList	makePairList();
		void		sorting(listOfList& list);
		void		copyToMainLst(listOfList tmpLst);
		bool		continueRec(listOfList &lst);
		void		creatMainChainPend(listOfList &lst);
		void		stockLast(listOfList &lst);
		void		insertingList();
		void		recursionList();
	
	public:
		PmergeMe();
		PmergeMe(char **av);
		PmergeMe(const PmergeMe &mer);
		PmergeMe &operator=(const PmergeMe &mer);
		~PmergeMe();
		
		void	print(vecOfVec mainVec);
		void	print(vector mainVec);
		void	print(list mainVec);
		void	print(listOfList mainVec);
};
