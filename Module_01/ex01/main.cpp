/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 11:44:29 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/08/09 15:24:39 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie	*x=NULL;

	x = zombieHorde(3, "zak");
	for (int i = 0; i < 3; i++)
		if (x)
			x[i].annouce();	
	delete []x;
	return (0);
}
