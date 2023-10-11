/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 12:00:07 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/10/11 13:55:15 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

class Span
{
	private:
		unsigned int N;
		std::vector<int> arr;
	public:
		Span();
		Span(unsigned int n);
		Span(const Span &sp);
		Span &operator = (const Span &sp);
		~Span();

		void	addNumber(int x);
		void	addNumbers(std::vector<int>&v);
		int		shortestSpan();
		int		longestSpan();
		std::vector<int>	getArr();
};
