/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 16:13:45 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/10/23 12:14:02 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int main(int ac, char **av)
{
	if (ac != 4)
		return (1);
	else
	{
		std::string strFull;
		std::string str = av[1];
		
		std::ifstream inpF(av[1]);
		if (inpF.fail())
			return (2);

		std::ofstream outF(str + ".replace");
		if (outF.fail())
			return (3);
		
		size_t x;

		str = av[2];
		while (1)
		{
			std::getline(inpF, strFull);
			strFull = strFull + '\n';
			x = strFull.find(av[2], 0);
			while (x != strFull.npos)
			{
				x = strFull.find(av[2], 0);
				if (x != strFull.npos)
				{
					strFull.erase(x, str.length());
					strFull.insert(x, av[3]);	
				}
			}
			outF << strFull;
			if (inpF.eof())
				break ;
		}
		inpF.close();
		outF.close();
	}
	return (0);
}