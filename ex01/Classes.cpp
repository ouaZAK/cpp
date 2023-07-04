#include "header.hpp"

int PhoneBook::check(std::string av)
{
	if (!av.compare("ADD"))
		return (ADD);
	else if (!av.compare("SEARCH"))
		return (SEARCH);
	else if (!av.compare("exit"))
		return (EXIT);
	return (0);
}

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


void	PhoneBook::adding(std::string av, int i, int n)
{
	// do
	// {
		if (i == 0)
		{
			std::cout << "enter first name : ";
			std::cin >> av;
			this->contacts[n].set_str(av, i);
		}
		else if (i == 1)
		{
			std::cout << "enter last name : ";
			std::cin >> av;
			this->contacts[n].set_str(av, i);
		}
		else if (i == 2)
		{
			std::cout << "enter nickname : ";
			std::cin >> av;
			this->contacts[n].set_str(av, i);
		}
		else if (i == 3)
		{
			std::cout << "enter phone number : ";
			std::cin >> av;
			this->contacts[n].set_str(av, i);
		}
		else if (i == 4)
		{
			std::cout << "enter darkest secret : ";
			std::cin >> av;
			this->contacts[n].set_str(av, i);
		}
		
	// }
	// while (i < 5);
}

void	Contact::get_str()
{
	
	PhoneBook ph;
	std::cout << "here it is = " << this->first_name;
}

void	PhoneBook::display()
{
	this->contacts[0].get_str();
}