/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 09:00:10 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/11/22 09:57:08 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IdGen.hpp"

int main()
{
	Base *ptr;
	Base p;
	
	ptr = generate();
	identify(ptr);
	identify(p);
	return (0);
}