#ifndef SCALARCONVERT_HPP
# define SCALARCONVERT_HPP

# include <iostream>
# include <math.h>
#include <limits>

# define MIN_CHAR std::numeric_limits<char>::min() //-128
# define MAX_CHAR std::numeric_limits<char>::max() //127
# define MIN_INT std::numeric_limits<int>::min() //-2147483648
# define MAX_INT std::numeric_limits<int>::max() //2147483647
# define MIN_FLOAT -std::numeric_limits<float>::max() //-3.40282e+38
# define MAX_FLOAT std::numeric_limits<float>::max() //3.40282e+38
# define MIN_DOUBLE -std::numeric_limits<double>::max() //-1.79769e+308
# define MAX_DOUBLE std::numeric_limits<double>::max() //1.79769e+308

void	error_print(void);
void	print_char(const char c);
void	print_int(const int i);
void	print_float(const float f);
void	print_double(const double d);

class ScalarConverter
{
	private:
		ScalarConverter() {};
		ScalarConverter(const ScalarConverter &src);
		ScalarConverter &operator=(const ScalarConverter &src);
		~ScalarConverter() {};

	public:
		static void	convert(const std::string& str);
};

#endif 