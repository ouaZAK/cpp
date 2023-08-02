/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 19:52:01 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/08/02 16:38:21 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int					fix;
		static const int	frac;
	public:
		Fixed();
		Fixed(const int n);
		Fixed(const float n);
		Fixed(const Fixed &fP);
		Fixed &operator = (const Fixed &fP);
		~Fixed();
		
		bool	operator > (const Fixed &fP);
		bool	operator < (const Fixed &fP);
		bool	operator >= (const Fixed &fP);
		bool	operator <= (const Fixed &fP);
		bool	operator == (const Fixed &fP);
		bool	operator != (const Fixed &fP);
		
		Fixed	operator + (const Fixed &fP);
		Fixed	operator - (const Fixed &fP);
		Fixed	operator * (const Fixed &fP);
		Fixed	operator / (const Fixed &fP);
		
		Fixed	operator ++ ();
		Fixed	operator -- ();
		Fixed	operator ++ (int);
		Fixed	operator -- (int);
		
		int 	getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
		static Fixed		&min(Fixed &fP, Fixed &sP);
		static Fixed		&max(Fixed &fP, Fixed &sP);
		static const Fixed	&min(const Fixed &fP, const Fixed &sP);
		static const Fixed	&max(const Fixed &fP, const Fixed &sP);

};

std::ostream &operator<< (std::ostream &out, const Fixed &fP);

#endif