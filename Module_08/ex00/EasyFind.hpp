/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 11:58:33 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/10/05 11:59:46 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
template <typename T>
void easyFind(const T &t, const int &i)
{
	if (std::find(t.begin(), t.end(), i) == t.end())
		throw (std::exception());
}
