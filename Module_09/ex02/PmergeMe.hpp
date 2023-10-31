/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 07:50:33 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/10/31 09:04:47 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <deque>
#include <list>
#include <sstream>

class PmergeMe
{
	private:
		std::deque< std::deque<int> >	pairs;
		std::deque<int>					rest;
		std::deque<int>					tmp;
		std::deque<int>					x;
		std::string 					str;
		int								nbr;
		PmergeMe();
	public:
		PmergeMe(char **av);
		PmergeMe(const PmergeMe &mer);
		PmergeMe &operator=(const PmergeMe &mer);
		~PmergeMe();
		void	checkErrors();
		void	recursion();
		std::deque< std::deque<int> > getPairs();
};

std::ostream &operator<<(std::ostream &out, const std::deque<int> &dec);
