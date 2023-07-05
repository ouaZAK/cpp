#include "header.hpp"

int PhoneBook::check_valid(std::string av, PhoneBook phone, int n)
{
	(void)phone;
	this->contacts[n - 1].get_cnt(av, n);
	return (1);
}

int main()
{
	PhoneBook phone;
	std::string av;
	int	n;
	int	stop;

	n = 0;
	stop = 1;
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
			else if (n == 8)
				n--;
		}
		else if ((int)phone.check(av) == SEARCH)
		{
			phone.display(n);
			do
			{
				std::cout << "choose an index number : ";
				std::getline(std::cin, av);
				if (phone.check_valid(av, phone, n))
					stop = 0;
				else
					std::cout << "wrong index\n";
			}
			while (stop);
		}
	}
	while (1);
}