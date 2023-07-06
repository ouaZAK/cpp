#ifndef HEADER_HPP
#define HEADER_HPP

#include <iostream>
#include <cstdlib>
#include <string.h>

#define ADD 1
#define SEARCH 2
#define EXIT 3

class Contact {
	private :
		int	index;
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_number;
		std::string	darkest_secret;

	public :
		void	set_index(int n);
		int		get_index();
		void	set_str(std::string str, int i);
		void	get_str();
		void	get_cnt();
};

class PhoneBook {
	private :
		Contact contacts[8];
	
	public :
		int		check_valid(std::string av, int n);
		int		check(std::string av);
		void	adding(std::string av, int i, int);
		void	display(int n);
};

#endif