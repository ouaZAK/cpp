#include "header.hpp"

int PhoneBook::check(std::string av)
{
	if (!av.compare("ADD"))
		return (ADD);
	else if (!av.compare("SEARCH"))
		return (SEARCH);
	else if (!av.compare("exit"))
		return (EXIT);
	// std::cout << "la" << std::endl;
	return (0);
}

void	Contact::set_index(int n)
{
	this->index = n;
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
		if (i == 0)
		{
			std::cout << "enter first name : ";
			std::getline(std::cin, av);
			this->contacts[n].set_str(av, i);
		}
		else if (i == 1)
		{
			std::cout << "enter last name : ";
			std::getline(std::cin, av);
			this->contacts[n].set_str(av, i);
		}
		else if (i == 2)
		{
			std::cout << "enter nickname : ";
			std::getline(std::cin, av);
			this->contacts[n].set_str(av, i);
		}
		else if (i == 3)
		{
			std::cout << "enter phone number : ";
			std::getline(std::cin, av);
			this->contacts[n].set_str(av, i);
		}
		else if (i == 4)
		{
			std::cout << "enter darkest secret : ";
			std::getline(std::cin, av);
			this->contacts[n].set_str(av, i);
		}
		this->contacts[n].set_index(n + 1);
}

void	print_space(int size)
{
	while (size < 10)
	{
		std::cout <<' ';
		size++;
	}
}

void	Contact::get_str()
{
	// std::cout << "s " << size  << std::endl;
	// std::cout << "l " << this->first_name.length()  << std::endl;
	std::cout	<< "|" << this->index
				<< "         "
				<< "|";
	if (this->first_name.length() >= 10)
	{
		//copy the name into a tmp and truncat it to '.'
		std::string tmp;
		tmp.copy(this->first_name, 9, 0);
	}
	std::cout	<< this->first_name;
	print_space(this->first_name.size());

	std::cout	<< "|" << this->last_name;
	print_space(this->last_name.size());

	std::cout	<< "|" << this->nickname;
	print_space(this->nickname.size());
	std::cout	<< std::endl;
}

void	PhoneBook::display(int n)
{
	std::cout	<< "|" << "   index  "
				<< "|" << "first name"
				<< "|" << "last name "
				<< "|" << " nickname "
				<< std::endl;
	for (int i = 0; i < n; i++)
		this->contacts[i].get_str();
}
