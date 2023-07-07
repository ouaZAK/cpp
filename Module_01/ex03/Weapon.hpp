#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <string.h>

class Weapon
{
	private :
		std::string type;
	public :
		Weapon(std::string str)
		{
			setType(str);
		}
		void	setType(std::string str);
		std::string const	&get_type();
};

#endif