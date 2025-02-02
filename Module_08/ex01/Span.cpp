/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 12:00:00 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/10/30 10:44:16 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : N(0) {}

Span::Span(unsigned int n) : N(n) {}

Span::Span(const Span &sp)
{
	if (this != &sp)
		*this = sp;
}

Span &Span::operator = (const Span &sp)
{
	N = sp.N;
	std::copy(sp.arr.begin(), sp.arr.end(), arr.begin());
	return (*this);
}

Span::~Span(){}

void	Span::addNumber(int x)
{
	if (arr.size() >= N)
		throw (std::out_of_range("it has maximum numbers"));
	arr.push_back(x);
}

void	Span::addNumbers(std::vector<int>&v)
{
	if (arr.size() >= N)
		throw (std::out_of_range("it has maximum numbers"));

	arr.insert(arr.begin(), v.begin(), v.end());
}

int	Span::shortestSpan()
{
	if (arr.size() <= 1)
		throw (std::out_of_range("no span can be found"));

	std::vector<int>::iterator it;
	int	result;
	int	sub;

	result = INT_MAX;
	std::sort(arr.begin(), arr.end());
	for (it = arr.begin(); it + 1 != arr.end(); it++)
	{
		sub = *(it + 1) - *it;
		if (sub < result)
			result = sub;
	}
	return (result);
}

int	Span::longestSpan()
{
	if (arr.size() <= 1)
		throw (std::out_of_range("no span can be found"));

	std::vector<int>::iterator itBegin, itEnd;
	
	std::sort(arr.begin(), arr.end());
	itBegin = arr.begin();
	itEnd = arr.end() - 1;
	return (*itEnd - *itBegin);
}

std::vector<int>	Span::getArr()
{
	return (arr);
}
