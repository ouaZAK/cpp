#include "header.hpp"

int PhoneBook::check_valid(std::string av, PhoneBook phone, int n)
{
	(void)phone;
	int i;

	char s[av.length()];
	av.copy(s, av.length());
	i = atoi(s);
	if (i >= 1 && i <= 8 && i <= n)
	{
		this->contacts[i-1].get_cnt(av, i);
		return (1);
	}
	return (0);
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
			else if (n == 3)
			{
				phone.display(n);
				n = 2;
			}
			else
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