/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 19:51:58 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/08/14 12:04:06 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::frac = 8;

Fixed::Fixed() : fix(0)
{
	std::cout << "default constructor called" << std::endl;
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