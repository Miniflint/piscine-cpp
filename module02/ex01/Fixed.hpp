#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed {
	private:
		int					_fixedFloatingPts;
		static const int	_bits = 8;
	public:
		Fixed(void);
		Fixed(int nb);
		Fixed(float nb);
		Fixed(const Fixed &old);
		~Fixed(void);
		int		getRawBits( void ) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
		Fixed	&operator=(const Fixed &old);
};
std::ostream	&operator<<(std::ostream &os, const Fixed &old);

#endif