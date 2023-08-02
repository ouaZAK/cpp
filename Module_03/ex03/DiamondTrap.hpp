/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 12:50:02 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/08/01 19:07:48 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	private:
		std::string name;
	public:
		DiamondTrap();
		DiamondTrap(const std::string &name);
		DiamondTrap(const DiamondTrap &diam);
		DiamondTrap &operator = (const DiamondTrap &diam);
		~DiamondTrap();
		void	attack(const std::string &target);
		void	whoAmI(void);
};

#endif