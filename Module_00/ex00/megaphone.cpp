/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 13:05:16 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/07/30 17:00:14 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int ac, char **av)
{
	if (ac == 1)
	std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
		for (int i = 1; i < ac; i++)
			for (int j = 0; av[i][j]; j++)
				std::cout << (char)toupper(av[i][j]);
				
	std::cout << std::endl;
	return (0);
}