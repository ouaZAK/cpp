#ifndef HEADER_HPP
#define HEADER_HPP

#include <iostream>
#include <cstdlib>

#define ADD 1
#define SEARCH 2
#define EXIT 3

class Contact {
	private :
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_number;
		std::string	darkest_secret;

		int	index;

	public :
		void	set_str(std::string str, int i);
		void	get_str();
};

class PhoneBook {
	private :
		Contact contacts[8];
	
	public :
		int		check(std::string av);
		void	adding(std::string av, int i, int);
		void	display();
};

#endif