/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 19:52:01 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/08/01 20:06:39 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int					fix;
		static const int	frac;
	public:
		Fixed();
		Fixed(const Fixed &fP);
		Fixed &operator = (const Fixed &fP);
		~Fixed();
		int 	getRawBits(void) const;
		void	setRawBits(int const raw);
};



#endif