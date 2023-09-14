/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 18:53:55 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/09/13 10:28:25 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap x("zak");
	std::cout << "----------\n";
	x.attack("lala");
	x.guardGate();
	x.whoAmI();
	x.takeDamage(5);
	x.highFiveGuys();
	x.beRepaired(1);
	// DiamondTrap y(x);
	// y.whoAmI();
	std::cout << "----------\n";
	// x.whoAmI();
	// x.attack("la");
	// // DiamondTrap y(x);
	// x.whoAmI();
	
	// y.attack("la");
	// DiamondTrap y(x);
	
	// ss.attack("lala");
	// ss.guardGate();
	// ScavTrap a("fist");
	// FragTrap b("ka");
	// std::cout << "----------\n";
	
	// a.attack("wall");
	// a.beRepaired(3);
	// a.takeDamage(13);
	// a.takeDamage(3);
	return (0);
}