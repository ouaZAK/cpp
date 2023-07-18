#include "Fixed.hpp"

Fixed::Fixed(void) : fix(0)
{
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int x)
{
	// std::cout << "Int constructor called" << std::endl;
	std::cout << x<<std::endl; // remove this
}

Fixed::Fixed(const float y)
{
	std::cout << "Float constructor called" << std::endl;
	???????????
}

Fixed::Fixed(const Fixed &fP) : fix(fP.fix) // copy 
{
	std::cout << "Copy constructor called" << std::endl;
	???????????
}

Fixed	&Fixed::operator=(const Fixed &fP)
{
	// std::cout << "Copy assignement operator called" << std::endl;
	this->setRawBits(fP.getRawBits());
	return (*this); // return reference (*this) is reference in copy assignement otherwise its a dereference
}

Fixed::~Fixed(void)
{
	// std::cout << "Destructor called" << std::endl;
}

int		Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->fix);
}

void	Fixed::setRawBits(int const raw)
{
	this->fix = raw;
}

std::ostream	&operator << (std::ostream &out, Fixed const &f)
{
	// out << f.toFloat();
	out << f.getRawBits();
	return (out);
}


bool	Fixed::operator > (Fixed const &f)
{
	return (this->getRawBits() > f.getRawBits());
}

bool	Fixed::operator < (Fixed const &f)
{
	return (this->getRawBits() < f.getRawBits());
}

bool	Fixed::operator >= (Fixed const &f)
{
	return (this->getRawBits() >= f.getRawBits());
}

bool	Fixed::operator <= (Fixed const &f)
{
	return (this->getRawBits() <= f.getRawBits());
}

bool	Fixed::operator == (Fixed const &f)
{
	return (this->getRawBits() == f.getRawBits());
}

bool	Fixed::operator != (Fixed const &f)
{
	return (this->getRawBits() != f.getRawBits());
}

Fixed	Fixed::operator + (Fixed const &f)
{
	Fixed	sum;
	sum.fix = fix + f.fix;
	return (sum);
}

Fixed	Fixed::operator - (Fixed const &f)
{
	Fixed	sub;
	sub.fix = fix - f.fix;
	return (sub);
}

Fixed	Fixed::operator * (Fixed const &f)
{
	Fixed	mul;
	mul.fix = fix * f.fix;
	return (mul);
}

Fixed	Fixed::operator / (Fixed const &f)
{
	Fixed	div;
	div.fix = fix / f.fix;
	return (div);
}

Fixed	Fixed::operator++()
{
	Fixed tmp;
	tmp.fix = ++fix;
	return (tmp);
}

Fixed	Fixed::operator++(int)
{
	Fixed tmp;
	tmp.fix = fix++;
	return (tmp);
}

Fixed	Fixed::operator--()
{
	Fixed tmp;
	tmp.fix = --fix;
	return (tmp);
}

Fixed	Fixed::operator--(int)
{
	Fixed tmp;
	tmp.fix = fix--;
	return (tmp);
}

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return (b);
	return (a);
}

const Fixed	&Fixed::min(Fixed const &a, Fixed const &b)
{
	if (a.getRawBits() > b.getRawBits())
		return (b);
	return (a);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return (a);
	return (b);
}

const Fixed	&Fixed::max(Fixed const &a, Fixed const &b)
{
	if (a.getRawBits() > b.getRawBits())
		return (a);
	return (b);
}