#ifndef V_HPP
#define V_HPP


#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int nbr;
		const int frac = 8;
	public:
		Fixed();
		Fixed(const int x) : nbr(x << frac) {}
		Fixed(const float y):nbr(roundf(nbr * (1 << 8))) {}
		Fixed(const Fixed &fix)
		{
			*this = fix;
		}
		Fixed &operator=(const Fixed &fix)
		{
			setRaw(fix.getRaw());
			return (*this);
		}
		int		toInt(void) const
		{
			return (nbr >> 8);
		}
		float	toFloat(void) const
		{
			return ((float)nbr / (1 << 8));
		}
		void setRaw(int const x)
		{
			nbr = x;
		}
		int	 getRaw()
		{
			return (nbr);
		}
};

std::ostream &operator<<(std::ostream &out, const Fixed &fix)
{
	out << fix.toFloat();
	return (out);
}

#endif