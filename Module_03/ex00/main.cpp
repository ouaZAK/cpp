/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 18:53:55 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/07/31 19:53:02 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap a("fist");

	a.attack("wall");
	a.beRepaired(3);
	a.takeDamage(13);
	a.takeDamage(3);
	return (0);
}