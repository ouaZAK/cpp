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
		Fixed(const Fixed &f);
		Fixed	&operator = (const Fixed &f);
		~Fixed();
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif