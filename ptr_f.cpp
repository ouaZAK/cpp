#include <iostream>

class Harl
{
	private :
	public :
		void	lala(void);
		void complane(std::string lvl);
};

void	Harl::lala(void)
{
	std::cout << "lala"<<std::endl;
}

int main()
{
	Harl test;
	void (Harl::*ex)() = &Harl::lala;

	(test.*ex)();
}