/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 10:14:52 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/10/06 11:38:25 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iosteram>

template <typename T>
class MutantStack
{
	private:
		
	public:
		MutantStack();
		MutantStack(const MutantStack &mut);
		MutantStack &operator=(const MutantStack &mut);
		~MutantStack();
};