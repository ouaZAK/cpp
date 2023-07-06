#include "header.hpp"

void	Contact::set_str(std::string str, int i)
{
	if (i == 0)
		this->first_name = str;
	else if (i == 1)
		this->last_name = str;
	else if (i == 2)
		this->nickname = str;
	else if (i == 3)
		this->phone_number = str;
	else if (i == 4)
		this->darkest_secret = str;
}

std::string	get_input(std::string av, char *str)
{
	int stop;

	stop = 1;
	do
	{
		std::cout << str;
		std::getline(std::cin, av);
		if (av.empty())
			std::cout << "write something"<< std::endl;
		else
			stop = 0;
	}while (stop);
	return (av);
}

void	PhoneBook::adding(std::string av, int i, int n)
{
	if (i == 0)
	{
		av = get_input(av, (char *)"enter first name : ");
		this->contacts[n].set_str(av, i);
	}
	else if (i == 1)
	{
		av = get_input(av, (char *)"enter last name : ");
		this->contacts[n].set_str(av, i);
	}
	else if (i == 2)
	{
		av = get_input(av, (char *)"enter nickname : ");
		this->contacts[n].set_str(av, i);
	}
	else if (i == 3)
	{
		av = get_input(av, (char *)"enter phone number : ");
		this->contacts[n].set_str(av, i);
	}
	else if (i == 4)
	{
		av = get_input(av, (char *)"enter darkest secret : ");
		this->contacts[n].set_str(av, i);
	}
	this->contacts[n].set_index(n + 1);
}
