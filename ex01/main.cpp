#include "header.hpp"

int main()
{
	PhoneBook phone;
	std::string av;
	int	n;
	// int	stop;

	n = 0;
	// stop = 1;
	do
	{
		std::cout << "type ADD, SEARCH or EXIT : ";
		std::getline(std::cin, av);
		// std::cout << "<" << av << ">";
		if (!(int)phone.check(av))
		{
			std::cout << "entre valid input" << std::endl;
			continue;
		}
		else if ((int)phone.check(av) == EXIT)
			exit(0);
		else if ((int)phone.check(av) == ADD)
		{
			for (int i = 0; i < 5; i++)
				phone.adding(av, i, n);
			if (n != 8)
				n++;
		}
		else if ((int)phone.check(av) == SEARCH)
			phone.display(n);
	}
	while (1);
}