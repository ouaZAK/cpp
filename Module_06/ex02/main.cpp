/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 09:00:10 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/12/01 10:35:23 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IdGen.hpp"

class D : public Base 
{
	
};

int main()
{
	// Base *ptr;
	Base p;
	A a;
	B b;
	D d;
	// ptr = generate();
	// identify(ptr);
	identify(&d);
	return (0);
}