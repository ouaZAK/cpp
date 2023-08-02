/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 12:12:09 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/07/31 15:24:24 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	HUMANB_HPP
#define	HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
	private:
		Weapon		*b;
		std::string name;

	public:
		HumanB(std::string name);
		~HumanB();
		void	attack() const;
		void	setWeapon(Weapon &wep);
};

#endif