/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 12:12:04 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/07/31 15:22:08 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	HUMANA_HPP
#define	HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
	private:
		std::string name;
		Weapon		&a;

	public:
		HumanA(std::string name, Weapon &wep);
		~HumanA();
		void	attack() const;
};

#endif