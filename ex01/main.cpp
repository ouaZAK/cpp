#include "header.hpp"

int main()
{
	PhoneBook phone;
	std::string av;
	int	n;

	n = 0;
	do
	{
		std::cout << "type ADD, SEARCH or EXIT : ";
		std::cin >> av;
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
		}
		else if ((int)phone.check(av) == SEARCH)
			phone.display();
	}
	while (1);
}