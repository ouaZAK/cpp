/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 07:55:55 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/11/28 10:08:13 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>

class RPN
{
	private:
		std::vector<double>	v;
		std::string			line;
		std::string			str;
		double				d;
		RPN();
	public:
		RPN(char *av);
		RPN(const RPN &rpn);
		RPN &operator=(const RPN &rpn);
		~RPN();

		void	calculate();
		void	readLine();
		double	whichSign(std::string::iterator &it, std::vector<double>::iterator vit);
};