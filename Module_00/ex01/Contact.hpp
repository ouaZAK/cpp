/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 13:28:47 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/07/31 12:46:22 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <iomanip>
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
		Contact();
		~Contact();
		void	set_index(int n);
		int		get_index(void);
		void	set_str(std::string str, int i);
		void	get_str(void);
		void	get_cnt(void);
};

#endif