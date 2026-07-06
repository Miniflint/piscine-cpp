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
	this->_fixedFloatingPts = old.getRawBits();
	return (*this);
}

bool	Fixed::operator<(const Fixed &right) const
{
	return (this->_fixedFloatingPts < right.getRawBits());
}

bool	Fixed::operator>(const Fixed &right) const
{
	return (this->_fixedFloatingPts > right.getRawBits());
}

bool	Fixed::operator<=(const Fixed &right) const
{
	return (this->_fixedFloatingPts <= right.getRawBits());
}

bool	Fixed::operator>=(const Fixed &right) const
{
	return (this->_fixedFloatingPts >= right.getRawBits());
}

bool	Fixed::operator==(const Fixed &right) const
{
	return (this->_fixedFloatingPts == right.getRawBits());
}

bool	Fixed::operator!=(const Fixed &right) const
{
	return (this->_fixedFloatingPts != right.getRawBits());
}

Fixed	&Fixed::operator+(const Fixed &right)
{
	this->_fixedFloatingPts = this->_fixedFloatingPts + right.getRawBits();
	return (*this);
}

Fixed	&Fixed::operator-(const Fixed &right)
{
	this->_fixedFloatingPts = this->_fixedFloatingPts - right.getRawBits();
	return (*this);
}

Fixed	&Fixed::operator*(const Fixed &right)
{
	this->_fixedFloatingPts = (this->_fixedFloatingPts * right.getRawBits()) >> this->_bits;
	return (*this);
}

Fixed	&Fixed::operator/(const Fixed &right)
{
	this->_fixedFloatingPts = (this->_fixedFloatingPts << this->_bits) / right.getRawBits();
	return (*this);
}

Fixed	&Fixed::operator++(void)
{
	this->_fixedFloatingPts++;
	return (*this);
}

Fixed	&Fixed::operator--(void)
{
	this->_fixedFloatingPts--;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	old = *this;
	old++;
	return (old);
}

Fixed	Fixed::operator--(int)
{
	Fixed	old = *this;
	old--;
	return (old);
}

Fixed	&Fixed::max(Fixed &left, Fixed &right)
{
	return (left > right ? left : right);
}

const Fixed &Fixed::max(const Fixed &left, const Fixed &right)
{
	return (left > right ? left : right);
}

Fixed	&Fixed::min(Fixed &left, Fixed &right)
{
	return (left < right ? left : right);
}

const	Fixed &Fixed::min(const Fixed &left, const Fixed &right)
{
	return (left < right ? left : right);
}

std::ostream    &operator<<(std::ostream &os, const Fixed &old)
{
	os << old.toFloat();
	return (os);
}
