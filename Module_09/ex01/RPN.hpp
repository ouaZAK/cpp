/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 07:55:55 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/10/21 08:01:54 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class RPN
{
	private:

	public:
		RPN();
		RPN(const RPN &rpn);
		RPN &operator=(const RPN &rpn);
		~RPN();
};