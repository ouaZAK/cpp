/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 18:53:55 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/08/01 11:45:49 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
	ScavTrap ss("zak");
	std::cout << "----------\n";
	ScavTrap s(ss);
	std::cout << "----------\n";
	
	ss.attack("lala");
	ss.guardGate();
	// ClapTrap a("fist");

	// a.attack("wall");
	// a.beRepaired(3);
	// a.takeDamage(13);
	// a.takeDamage(3);
	return (0);
}