#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
	private :
		std::string name;
		Weapon *wepA;
	public :
		HumanA(std::string str, Weapon &w): name(str), wepA(&w)
		{
		}
		void	attack();
};

#endif