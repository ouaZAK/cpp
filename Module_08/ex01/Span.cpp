/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 12:00:00 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/10/05 16:04:11 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : N(0)
{
}

Span::Span(unsigned int n) : N(n)
{
}

Span::Span(const Span &sp)
{
	*this = sp;
}

Span &Span::operator = (const Span &sp)
{
	if (this != &sp)
		(void)sp;
	return (*this);
}
Span::~Span()
{
}

void	Span::addNumber(int x)
{
	if (arr.size() >= N)
		throw (std::out_of_range("it has maximum numbers"));
	arr.push_back(x);
}

int	Span::shortestSpan()
{
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
	std::vector<int>::iterator itBegin, itEnd;

	std::sort(arr.begin(), arr.end());
	itBegin = arr.begin();
	itEnd = arr.end() - 1;
	return (*itEnd - *itBegin);
}