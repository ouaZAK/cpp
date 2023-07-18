#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	private :
		int					fix;
		static const int	bit = 8;
	public :
		Fixed(void);
		Fixed(const int x);
		Fixed(const float y);
		Fixed(const Fixed &f);
		Fixed	&operator = (const Fixed &f);
		~Fixed();

		bool	operator > (const Fixed &f);
		bool	operator >= (const Fixed &f);
		bool	operator < (const Fixed &f);
		bool	operator <= (const Fixed &f);
		bool	operator == (const Fixed &f);
		bool	operator != (const Fixed &f);
		Fixed	operator + (const Fixed &f);
		Fixed	operator - (const Fixed &f);
		Fixed	operator * (const Fixed &f);
		Fixed	operator / (const Fixed &f);
		Fixed	operator ++ ();
		Fixed	operator ++ (int);
		Fixed	operator -- ();
		Fixed	operator -- (int);

		static Fixed		&min(Fixed &a, Fixed &b);
		static Fixed		&max(Fixed &a, Fixed &b);
		static const Fixed	&min(Fixed const &a, Fixed const &b);
		static const Fixed	&max(Fixed const &a, Fixed const &b);
		
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		// float	toFloat( void ) const;
		// int		toInt( void ) const;
};

std::ostream	&operator << (std::ostream &out, Fixed const &f);

#endif