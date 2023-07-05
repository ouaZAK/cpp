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

int	Contact::get_index()
{
	return (this->index);
}

void	Contact::get_cnt(std::string av, int n)
{
	(void)n;
	(void)av;
	std::cout << "first name : " << this->first_name << std::endl;
	std::cout << "last name : " << this->last_name << std::endl;
	std::cout << "nickname : " << this->nickname << std::endl;
	std::cout << "phone number : " << this->phone_number << std::endl;
	std::cout << "darkest secret : " << this->darkest_secret << std::endl;
}

void	Contact::set_str(std::string str, int i)
{
	if (i == 0)
	{
		// if (this->first_name.empty())
		// 	this->first_name = str;
		// else
		// {
			std::cout << str << "= bef\n";
			this->first_name.erase(0);
			std::cout << str << "= aft\n";
			this->first_name = str;
		// }
	}
	else if (i == 1)
	{
		this->last_name.erase(0);
		this->last_name = str;
	}
	else if (i == 2)
	{
		this->nickname.erase(0);
		this->nickname = str;
	}
	else if (i == 3)
	{
		this->phone_number.erase(0);
		this->phone_number = str;
	}
	else if (i == 4)
	{
		this->darkest_secret.erase(0);
		this->darkest_secret = str;
	}
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

void	print(std::string str)
{
	int size;
	int i;
	std::string::iterator start;
	std::string::iterator end;

	i = 0;
	start = str.begin();
	end = str.end();
	while (start != end)
	{
		if (i < 9)
			std::cout << *start;
		else
		{
			std::cout << ".";
			break ;
		}
		i++;
		start++;
	}
	size = str.size();
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
	std::cout	<< "|" << this->index << "         " << "|";
	print(this->first_name);
	std::cout	<< "|";
	print(this->last_name);
	std::cout	<< "|";
	print(this->nickname);
	std::cout	<< "|";
	std::cout	<< std::endl;
}

void	PhoneBook::display(int n)
{
	std::cout	<< "|" << "   index  "
				<< "|" << "first name"
				<< "|" << "last name "
				<< "|" << " nickname "
				<< "|" << std::endl;
	for (int i = 0; i < n; i++)
		this->contacts[i].get_str();
}
