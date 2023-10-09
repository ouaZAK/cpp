/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 08:50:49 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/10/09 10:01:36 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int main()
{
	try
	{
		Bureaucrat b("z", 1);
		Form	f("a", 50, 30);

		b.signForm(f);
		std::cout << "-------------------\n";
		f.beSigned(b);
		std::cout << b;
		std::cout << "-------------------\n";
		std::cout << f << std::endl;
	}
	catch (std::exception &ex)
	{
		std::cerr << ex.what() << std::endl;
	}
	return (0);
}