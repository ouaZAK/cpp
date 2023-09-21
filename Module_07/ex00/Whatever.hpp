/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 10:30:16 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/09/21 11:05:54 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template <typename T>
void	swap(T &a, T &b)
{
	std::swap(a, b);
}

template <typename T>
const T &min(const T &a, const T &b)
{
	return (b <= a ? b : a);
}

template <typename T>
const T &max(const T &a, const T &b)
{
	return (b >= a ? b : a);
}