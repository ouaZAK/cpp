/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 19:51:58 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/08/01 20:06:33 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::frac = 8;

Fixed::Fixed()
{
	std::cout << "default constructor called" << std::endl;
	fix = 0;
}

Fixed::Fixed(const Fixed &fP)
{
	std::cout << "copy constructor called" << std::endl;
	*this = fP;
}

Fixed &Fixed::operator = (const Fixed &fP)
{
	std::cout << "copy assignement operator called" << std::endl;
	setRawBits(fP.getRawBits());
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called"<< std::endl;
	return (fix);
}

void	Fixed::setRawBits(int const raw)
{
	fix = raw;
}