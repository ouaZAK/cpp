#include "header.hpp"

int PhoneBook::check_valid(std::string av,int n)
{
	int i;
	char s[av.length()];

	av.copy(s, av.length());
	i = atoi(s);
	if (i >= 1 && i <= 8 && i <= n)
	{
		this->contacts[i - 1].get_cnt();
		return (1);
	}
	return (0);
}

int PhoneBook::check(std::string av)
{
	if (!av.compare("ADD"))
		return (ADD);
	else if (!av.compare("SEARCH"))
		return (SEARCH);
	else if (!av.compare("EXIT"))
		return (EXIT);
	return (0);
}

void	Contact::set_index(int n)
{
	this->index = n;
}

int	Contact::get_index(void)
{
	return (this->index);
}
