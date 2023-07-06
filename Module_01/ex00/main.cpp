#include "Zombie.hpp"

int main()
{
	std::string str;
	Zombie *z;
	Zombie	y;

	std::cout << "(created in stack)\n" <<"enter name :";
	std::cin >> str;
	randomChump(str);

	std::cout << "(created in heap)\n" << "enter name :";
	std::cin >> str;
	z = newZombie(str);
	z->annouce();
	delete z;
	std::cout << str << " destroyed"<<std::endl;
	return (0);
}