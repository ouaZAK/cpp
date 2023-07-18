#include "Fixed.hpp"

Fixed::Fixed(void) : fix(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int x)
{
	std::cout << "Int constructor called" << std::endl;

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
	std::cout << "Copy assignement operator called" << std::endl;
	this->setRawBits(fP.getRawBits());
	return (*this); // return reference (*this) is reference in copy assignement otherwise its a dereference
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fix);
}

void	Fixed::setRawBits(int const raw)
{
	this->fix = raw;
}

std::ostream	&operator << (std::ostream &out, Fixed const &f)
{
	out << f.toFloat();
	return (out);
}