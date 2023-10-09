/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 08:50:49 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/10/09 08:53:02 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat b("z", 1);
		std::cout << "the grade is < " << b.getGrade() << " >" << std::endl;
		b.dec();
		std::cout << "the grade is < " << b.getGrade() << " >" << std::endl;
		std::cout << b;
		std::cout << "the grade is < " << b.getGrade() << " >" << std::endl;
		b.inc();
		std::cout << "the grade is < " << b.getGrade() << " >" << std::endl;
		std::cout << b;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}