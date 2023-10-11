/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 10:26:56 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/10/11 13:50:08 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main()
{
	try
	{
		// unsigned int x = 2;
		// unsigned int y = 10;
		Array<unsigned int> a;
		// for (unsigned int i = 0; i < x; i++)
		// 	std::cout << a.myArr[i]<<"\n";
		std::cout << a.size() << "\n";
		// std::cout << "------------------" << "\n";
		std::cout << "x " << a[3] << "\n";
		// std::cout << "------------------" << "\n";
		// std::cout << a[10] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}