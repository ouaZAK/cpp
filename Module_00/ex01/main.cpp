#include "header.hpp"

int main()
{
	PhoneBook phone;
	std::string av;
	int	n;
	int	stop;

	n = 0;
	do
	{
		stop = 1;
		std::cout << "type ADD, SEARCH or EXIT : ";
		std::getline(std::cin, av);
		if (!(int)phone.check(av))
		{
			std::cout << "entre valid input" << std::endl;
			continue;
		}
		else if ((int)phone.check(av) == EXIT)
			exit(0);
		else if ((int)phone.check(av) == ADD)
		{
			if (n == 3)
				n = 2;
			for (int i = 0; i < 5; i++)
				phone.adding(av, i, n);
			if (n != 3)
				n++;
		}
		else if ((int)phone.check(av) == SEARCH)
		{
			if (!n)
			{
				std::cout << "empty" << std::endl;
				continue ;
			}
			else
				phone.display(n);
			do
			{
				std::cout << "choose an index number : ";
				std::getline(std::cin, av);
				if (phone.check_valid(av, n))
					stop = 0;
				else
					std::cout << "wrong index\n";
			}
			while (stop == 1);
		}
	}
	while (1);
}