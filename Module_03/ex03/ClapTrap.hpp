/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 18:53:53 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/08/01 11:06:36 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
	protected:
		std::string		name;
		unsigned int	hp;
		unsigned int	ep;
		unsigned int	ad;
	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &clap);
		ClapTrap &operator = (const ClapTrap &clap);
		~ClapTrap();
		void	attack(const std::string &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};

#endif