/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 19:51:58 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/08/02 16:02:29 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::frac = 8;

Fixed::Fixed()
{
	fix = 0;
	std::cout << "default constructor called" << std::endl;
}

Fixed::Fixed(const int n) : fix(n << frac)
{
	std::cout << "int constructor called" << std::endl;
}

Fixed::Fixed(const float n) : fix(roundf(n * (1 << frac)))
{
	std::cout << "float constructor called" << std::endl;
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
	return (fix);
}

void	Fixed::setRawBits(int const raw)
{
	fix = raw;
}

float	Fixed::toFloat(void) const
{
	return ((float)fix / (float)(1 << frac));
}

int	Fixed::toInt(void) const
{
	return (fix >> frac);
}

std::ostream &operator<< (std::ostream &out, const Fixed &fP)
{
	return (out << fP.toFloat());
}
