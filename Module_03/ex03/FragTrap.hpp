/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 11:56:39 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/08/01 17:45:44 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap &frag);
		FragTrap &operator = (const FragTrap &frag);
		~FragTrap();
		void	attack(const std::string &target);
		void	highFiveGuys(void);
};


#endif