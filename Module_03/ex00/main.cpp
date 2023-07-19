#include "ClapTrap.hpp"

int main()
{
	ClapTrap c1("c1");

	c1.setAtk(10);
	c1.attack("c2");
	c1.beRepaired(4);
	c1.takeDamage(10);
	c1.takeDamage(10);
	return (0);
}