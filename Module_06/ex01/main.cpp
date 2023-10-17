/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 07:46:34 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/10/14 12:30:26 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	uintptr_t	y;
	Data		d;
	
	d.x = 123;
	int x = 4;
	int *ptr 
	y = Serializer::serialize(&d);
	Data*	ptr = Serializer::deserialize(y);

	std::cout << "ptr: " << ptr->x << std::endl;
	std::cout << "address ptr: " << ptr << std::endl;
	std::cout << "address y: " << &y << std::endl;
	return (0);
}