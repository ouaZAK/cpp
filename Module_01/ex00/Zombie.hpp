/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 19:57:19 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/07/31 13:00:03 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string.h>

class Zombie
{
	private:
		std::string name;

	public:
		Zombie(std::string name);
		~Zombie();
		void		annouce(void);
		void		set_name(std::string name);
		std::string	get_name(void);
};

Zombie *newZombie(std::string name);
void	randomChump(std::string name);

#endif