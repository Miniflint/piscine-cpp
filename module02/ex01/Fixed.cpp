#include "Fixed.hpp"

Fixed::Fixed() : _fixedFloatingPts(0)
{
	std::cout << "Default constructor() called" << std::endl;
}

Fixed::Fixed(int nb) : _fixedFloatingPts(nb << this->_bits)
{
	std::cout << "Default constructor(int) called" << std::endl;
    return;
}
Fixed::Fixed(float nb) : _fixedFloatingPts(roundf(nb * (1 << this->_bits)))
{
	std::cout << "Default constructor(float) called" << std::endl;
    return ;
}

Fixed::~Fixed(void)
{
	std::cout << "Default Destructor called" << std::endl;
	return ;
}

Fixed::Fixed(const Fixed &old)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_fixedFloatingPts = old.getRawBits();
	return ;
}

int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixedFloatingPts);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_fixedFloatingPts = raw;
	return ;
}

float	Fixed::toFloat(void) const
{
    return ((float)this->_fixedFloatingPts / (float)(1 << this->_bits));
}

int		Fixed::toInt(void) const
{
	return (this->_fixedFloatingPts >> this->_bits);
}

Fixed	&Fixed::operator=(const Fixed &old)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_fixedFloatingPts = old.getRawBits();
	return (*this);
}


std::ostream    &operator<<(std::ostream &os, const Fixed &old)
{
	os << old.toFloat();
	return (os);
}
