/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 13:26:43 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/07/31 12:46:53 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact contacts[8];
	public:
		PhoneBook();
		~PhoneBook();
		int		check_valid(std::string av, int n);
		int		check(std::string av);
		void	adding(std::string av, int i, int);
		void	display(int n);
};

#endif