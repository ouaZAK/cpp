/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 08:50:49 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/09/04 12:11:34 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int main()
{
	try
	{
		Bureaucrat b("z", 1);
		Form	f("a", 50, 50);

		// b.inc();
		f.beSigned(b);
		b.signForm(f);
		std::cout << b << std::endl;
		std::cout << f << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &ex)
	{
		std::cerr << ex.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &ex)
	{
		std::cerr << ex.what() << std::endl;
	}
	catch (Form::GradeTooLowException &ex)
	{
		std::cerr << ex.what() << std::endl;
	}
	return (0);
}