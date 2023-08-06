/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 18:53:55 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/08/05 12:48:28 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap x("zak");
	// DiamondTrap y(x);
	// y.whoAmI();
	std::cout << "----------\n";
	// x.whoAmI();
	x.attack("la");
	// DiamondTrap y(x);
	x.whoAmI();
	std::cout << "----------\n";
	
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