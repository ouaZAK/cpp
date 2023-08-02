/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 12:01:26 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/07/31 12:08:52 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
	std::string	str = "HI THIS IS BRAIN";
	std::string	*stringPTR = &str;
	std::string	&stringREF = str;
	
	std::cout << "addr of str : " << &str << std::endl;
	std::cout << "addr hold by PTR : " << stringPTR << std::endl;
	std::cout << "addr of REF : " << &stringREF << std::endl;

	std::cout << "---------------------" << std::endl;
	
	std::cout << "value of str : " << str << std::endl;
	std::cout << "value hold by PTR : " << *stringPTR << std::endl;
	std::cout << "value of REF : " << stringREF << std::endl;
	return (0);
}