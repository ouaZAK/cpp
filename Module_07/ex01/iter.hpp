/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:04:51 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/09/21 12:32:54 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template <typename T>
void	myFunc(T &ar)
{
	std::cout << "arr : " << ar << std::endl;
}

template <typename T>
void	iter(T *arr, int length, void (*func)(T &ar))
{
	for (int i = 0; i < length; i++)
		(*func)(arr[i]);
}