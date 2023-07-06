#include "Zombie.hpp"

int main()
{
	Zombie	*z;

	z = zombieHorde(4, "zak");
	for (int i = 0; i < 4; i++)
		z[i].annouce();
	delete []z;
	return (0);
}