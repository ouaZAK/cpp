/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 19:56:51 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/07/31 13:06:02 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie	x("ha");
	Zombie	*y;

	// x.set_name("lala");
	x.annouce();
	y = newZombie("haha");
	y->annouce();
	delete (y);
	return (0);
}