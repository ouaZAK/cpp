/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 07:55:52 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/10/21 08:33:35 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
}

RPN::RPN(const RPN &rpn)
{
	if (this != &rpn)
		*this = rpn;
}

RPN	&RPN::operator=(const RPN &rpn)
{
	(void)rpn;
	return (*this);
}

RPN::~RPN()
{
}