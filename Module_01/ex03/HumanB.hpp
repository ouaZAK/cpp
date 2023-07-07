#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
	private :
		Weapon* wepB;
		std::string name;
	public :
		HumanB(std::string str) : name(str)
		{
			this->wepB = NULL;
		}
		void	attack();
		void	setWeapon(Weapon &w);
};

#endif