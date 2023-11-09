/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 07:50:33 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/11/09 12:57:34 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <deque>
#include <list>
#include <sstream>


typedef std::deque< std::deque<int> > deqOfDeq;
typedef	std::deque<int> deque;

class PmergeMe
{
	private:
		deqOfDeq				mainDeq;
		deqOfDeq				TmpOfDeq;
		deque					pair;
		deque					last;
		deqOfDeq::iterator		pddIt;
		deqOfDeq::iterator		ddIt;
		deque::iterator			dIt;
		std::string 			str;
		size_t					cof;
		int						nbr;
		// int						count;
		int						nbrPairEqualCof;

		PmergeMe();
		void	recursion();
		void	checkAndStock();
		bool	check_cof();
		void	inserting(deque deq);
	public:
		PmergeMe(char **av);
		PmergeMe(const PmergeMe &mer);
		PmergeMe &operator=(const PmergeMe &mer);
		~PmergeMe();
		void	print(deqOfDeq mainDeq);
};

std::ostream &operator<<(std::ostream &out, const std::deque<int> &dec);
