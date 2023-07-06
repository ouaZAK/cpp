#include "header.hpp"

void	Contact::get_cnt()
{
	std::cout << "first name : " << this->first_name << std::endl;
	std::cout << "last name : " << this->last_name << std::endl;
	std::cout << "nickname : " << this->nickname << std::endl;
	std::cout << "phone number : " << this->phone_number << std::endl;
	std::cout << "darkest secret : " << this->darkest_secret << std::endl;
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
