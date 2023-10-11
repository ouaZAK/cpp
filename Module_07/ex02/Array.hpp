/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:22:59 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/10/11 13:49:17 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stdexcept>

template <typename T>
class Array
{
	private:
		T *myArr;
		unsigned int n;
	public:
		Array();
		Array(unsigned int &n);
		Array(const Array &arr);
		Array &operator=(const Array &arr);
		~Array();
		unsigned int	size(void) const;
		T &operator[](unsigned long n);
};

#include "Array.tpp"