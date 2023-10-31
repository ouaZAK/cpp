/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 19:56:51 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/10/26 13:07:09 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie	x("ha");
	Zombie	*y = NULL;

	x.annouce();
	y = newZombie("haha");
	if (y)
		y->annouce();
	
	delete (y);
	return (0);
}