/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 19:51:58 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/08/02 16:42:36 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::frac = 8;

Fixed::Fixed()
{
	fix = 0;
	// std::cout << "default constructor called" << std::endl;
}

Fixed::Fixed(const int n) : fix(n << frac)
{
	// std::cout << "int constructor called" << std::endl;
}

Fixed::Fixed(const float n) : fix(roundf(n * (1 << frac)))
{
	// std::cout << "float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fP)
{
	// std::cout << "copy constructor called" << std::endl;
	*this = fP;
}

Fixed &Fixed::operator = (const Fixed &fP)
{
	// std::cout << "copy assignement operator called" << std::endl;
	setRawBits(fP.getRawBits());
	return (*this);
}

Fixed::~Fixed()
{
	// std::cout << "destructor called" << std::endl;
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
	out << fP.toFloat();
	return (out);
}

bool	Fixed::operator > (const Fixed &fP)
{
	if (this->toFloat() > fP.toFloat())
		return (true);
	return (false);
}

bool	Fixed::operator < (const Fixed &fP)
{
	if (this->toFloat() < fP.toFloat())
		return (true);
	return (false);
}

bool	Fixed::operator >= (const Fixed &fP)
{
	if (this->toFloat() >= fP.toFloat())
		return (true);
	return (false);
}

bool	Fixed::operator <= (const Fixed &fP)
{
	if (this->toFloat() <= fP.toFloat())
		return (true);
	return (false);
}

bool	Fixed::operator == (const Fixed &fP)
{
	if (this->toFloat() == fP.toFloat())
		return (true);
	return (false);
}

bool	Fixed::operator != (const Fixed &fP)
{
	return (this->toFloat() != fP.toFloat());
}

Fixed	Fixed::operator + (const Fixed &fP)
{
	Fixed x;
	
	x = this->toFloat() + fP.toFloat();
	return (x);
}

Fixed	Fixed::operator - (const Fixed &fP)
{
	Fixed x;
	
	x = this->toFloat() - fP.toFloat();
	return (x);
}

Fixed	Fixed::operator * (const Fixed &fP)
{
	Fixed x;
	
	x = this->toFloat() * fP.toFloat();
	return (x);
}

Fixed	Fixed::operator / (const Fixed &fP)
{
	Fixed x;
	
	x = this->toFloat() / fP.toFloat();
	return (x);
}

Fixed	Fixed::operator ++ ()
{
	fix++;
	return (*this);
}

Fixed	Fixed::operator -- ()
{
	fix--;
	return (*this);
}

Fixed	Fixed::operator ++ (int)
{
	Fixed tmp;

	tmp = *this;
	fix++;
	return (tmp); // return an old copy but the original fix is incremented
}

Fixed	Fixed::operator -- (int)
{
	Fixed tmp;

	tmp = *this;
	fix--;
	return (tmp);
}

Fixed	&Fixed::min(Fixed &fP, Fixed &sP)
{
	if (fP < sP)
		return (fP);
	return (sP);
}

Fixed	&Fixed::max(Fixed &fP, Fixed &sP)
{
	if (fP > sP)
		return (fP);
	return (sP);
}

const Fixed	&Fixed::min(const Fixed &fP, const Fixed &sP)
{
	if ((Fixed)fP < (Fixed)sP) // there is no operator for const Fixed only Fixed operator
		return (fP);
	return (sP);
}

const Fixed	&Fixed::max(const Fixed &fP, const Fixed &sP)
{
	if ((Fixed)fP > (Fixed)sP)
		return (fP);
	return (sP);
}