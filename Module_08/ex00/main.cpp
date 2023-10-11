/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 10:53:11 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/10/11 13:53:35 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "EasyFind.hpp"

int main()
{
	std::vector<int> v;
	const int x = 95;

	for (int i = 96; i < 100; i++)
		v.push_back(i);

	try
	{
		easyFind(v, x);
		std::cout << "the number " << x << " exist" << std::endl; 
	}
	catch (const std::exception &e)
	{
		std::cout << "it doesn't exist" << std::endl;
	}
	
	return (0);
}