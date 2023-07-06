#ifndef Zombie_HPP
#define Zombie_hpp

#include <iostream>
#include <string.h>

class Zombie
{
	std::string name;

	public:
		void		annouce(void);
		void		set_name(std::string name);
		std::string	get_name(void);
};

Zombie* zombieHorde(int N, std::string name);

#endif