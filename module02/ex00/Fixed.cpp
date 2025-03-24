#include "Fixed.hpp"

Fixed::Fixed() : _fixedFloatingPts(0)
{
	std::cout << "Default constructor called" << std::endl;
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

Fixed	&Fixed::operator=(const Fixed &old)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_fixedFloatingPts = old.getRawBits();
	return (*this);
}