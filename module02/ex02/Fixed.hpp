#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed {
	private:
		int					_fixedFloatingPts;
		static const int	_bits = 8;
	public:
		Fixed();
		Fixed(int nb);
		Fixed(float nb);
		Fixed(const Fixed &old);
		~Fixed(void);
		int		getRawBits( void ) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

		Fixed	&operator=(const Fixed &old);
		bool	operator<(const Fixed &right) const ;
		bool	operator>(const Fixed &right) const ;
		bool	operator<=(const Fixed &right) const ;
		bool	operator>=(const Fixed &right) const ;
		bool	operator==(const Fixed &right) const ;
		bool	operator!=(const Fixed &right) const ;
		Fixed	&operator+(const Fixed &right);
		Fixed	&operator-(const Fixed &right);
		Fixed	&operator*(const Fixed &right);
		Fixed	&operator/(const Fixed &right);

		Fixed	&operator++(void);
		Fixed	&operator--(void);
		Fixed	operator++(int);
		Fixed	operator--(int);

		static Fixed	&max(Fixed &left, Fixed &right);
		static const	Fixed &max(const Fixed &left, const Fixed &right);
		static Fixed	&min(Fixed &left, Fixed &right);
		static const	Fixed &min(const Fixed &left, const Fixed &right);
};
std::ostream	&operator<<(std::ostream &os, const Fixed &old);

#endif