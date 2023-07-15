#include "Harl.hpp"

void	Harl::debug(void)
{
	std::cout << "start debugging" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "if it work dont touch it" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "stop right there" << std::endl;
}

void	Harl::error(void)
{
	std::cout << "good job, now get out" << std::endl;
}

void	Harl::complain(std::string level)
{
	void	(Harl::*ptr[])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string lvl[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++)
		if (lvl[i] == level)
			(this->*ptr[i])();
}