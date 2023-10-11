/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IdGen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 09:23:30 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/10/11 11:39:47 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IdGen.hpp"

Base	*generate(void)
{
	srand(time(NULL));//null mean return a numeric time_t value not readable for human// srand mean generate a random number so rand can be differente each time u called it
	int	x = (rand() % 3);
	std::cout << x << std::endl;
	switch (x)
	{
		case (0):
			return (new A);
		case (1):
			return (new B);
		case (2):
			return (new C);
	}
	return (new A);
}

void	identify(Base *p)
{
	if (!p)
		return ;
	A *a = dynamic_cast<A *>(p);
	if (a != NULL)
		std::cout << "A" << std::endl;
	B *b = dynamic_cast<B *>(p);
	if (b != NULL)
		std::cout << "B" << std::endl;
	C *c = dynamic_cast<C *>(p);
	if (c != NULL)
		std::cout << "C" << std::endl;
}

void	identify(Base &p)
{
	try
	{
		A a = dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
	}
	catch(...)
	{
		try
		{
			B b = dynamic_cast<B &>(p);
			std::cout << "B" << std::endl;
		}
		catch(...)
		{
			try
			{
				C c = dynamic_cast<C &>(p);
				std::cout << "C" << std::endl;
			}
			catch(...)
			{
			}
		}
	}
}
