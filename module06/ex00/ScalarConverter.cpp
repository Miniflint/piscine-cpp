#include "ScalarConverter.hpp"
#include <sstream>
#include <iomanip>

ScalarConverter::ScalarConverter(const ScalarConverter &src)
{
    *this = src;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src)
{
	(void)src;
	return (*this);
}

bool converts(const std::string &str, int &val)
{
	std::istringstream stream(str);
	stream >> val;
	return (stream.eof() && !stream.fail());
}

bool converts(const std::string &str, float &val)
{
	std::string removed;
	if (!str.empty() && str[str.size() - 1] == 'f')
		removed = str.substr(0, str.size() - 1);
	else 
		return (false);
	std::istringstream stream(removed);
	stream >> val;
	return (stream.eof() && !stream.fail());
}

bool converts(const std::string &str, double &val)
{
	std::istringstream stream(str);
	stream >> val;
	return (stream.eof() && !stream.fail());
}

void	ScalarConverter::convert(const std::string &str)
{
	int		i;
	float	f;
	double	d;

	const std::size_t t = str.find(".");
	if (str.length() == 1 && (str[0] > '9' || str[0] < '0'))
		print_char(str[0]);
	else if (converts(str, i))
		print_int(i);
	else if (converts(str, f) && t != std::string::npos && str[t + 1] >= '0' && str[t + 1] <= '9')
		print_float(f);
	else if (converts(str, d) && t != std::string::npos && str[t + 1] >= '0' && str[t + 1] <= '9')
		print_double(d);
	else {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		if (str == "nan" || str == "nanf") {
			std::cout << "float: nanf" << std::endl;
			std::cout << "double: nan" << std::endl;
		} else if (str == "+inf" || str == "+inff") {
			std::cout << "float: +inff" << std::endl;
			std::cout << "double: +inf" << std::endl;
		} else if (str == "-inf" || str == "-inff") {
			std::cout << "float: -inff" << std::endl;
			std::cout << "double: -inf" << std::endl;
		} else if (str == "inf" || str == "inff") {
			std::cout << "float: inff" << std::endl;
			std::cout << "double: inf" << std::endl;
		} else {
			std::cout << "float: impossible" << std::endl;
			std::cout << "double: impossible" << std::endl;
		}
	}
}

void	print_char(const char n)
{
	if (n <= 31 || n >= 127)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << n << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(n) << std::endl;
	std::cout << std::fixed <<std::setprecision(1) << "float: " << static_cast<float>(n) << "f"  << std::endl;
	std::cout << std::fixed <<std::setprecision(1) << "double: " << static_cast<double>(n) << std::endl;
}

void	print_int(const int n)
{
	// std::cout << "in int" << std::endl;
	char	c_convert;
	if (n >= MIN_CHAR && n <= MAX_CHAR)
	{
		c_convert = static_cast<char>(n);
		if (c_convert <= 31 || c_convert >= 127)
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: '" << c_convert << "'" << std::endl;
	}
	else
		std::cout << "char: overflow" << std::endl;
	std::cout << "int: " << n << std::endl;
	std::cout << std::fixed <<std::setprecision(1) << "float: " << static_cast<float>(n) << "f"  << std::endl;
	std::cout << std::fixed <<std::setprecision(1) << "double: " << static_cast<double>(n) << std::endl;
}

void	print_float(const float n)
{
	// std::cout << "in float" << std::endl;
	char	c_convert;
	if (n >= MIN_CHAR && n <= MAX_CHAR)
	{
		c_convert = static_cast<char>(n);
		if (c_convert <= 31 || c_convert >= 127)
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: '" << c_convert << "'" << std::endl;
	}
	else
		std::cout << "char: overflow" << std::endl;
	if (!isinf(n) && n == n)
	{
		if (n >= MIN_INT && n <= MAX_INT)
			std::cout << "int: " << static_cast<int>(n) << std::endl;
		else
			std::cout << "int: overflow" << std::endl;
	} else {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
	}
	std::cout << std::fixed <<std::setprecision(1) << "float: " << n << "f"  << std::endl;
	std::cout << std::fixed <<std::setprecision(1) << "double: " << static_cast<double>(n) << std::endl;
}

void	print_double(const double n)
{
	// std::cout << "in double" << std::endl;
	char	c_convert;
	if (n >= MIN_CHAR && n <= MAX_CHAR)
	{
		c_convert = static_cast<char>(n);
		if (c_convert <= 31 || c_convert >= 127)
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: '" << c_convert << "'" << std::endl;
	}
	else
		std::cout << "char: overflow" << std::endl;
	if (!isinf(n) && n == n)
	{
		if (n >= MIN_INT && n <= MAX_INT)
			std::cout << "int: " << static_cast<int>(n) << std::endl;
		else
			std::cout << "int: overflow" << std::endl;
	} else {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
	}
	if (n >= MIN_FLOAT && n <= MAX_FLOAT)
		std::cout << std::fixed <<std::setprecision(1) << "float: " << static_cast<float>(n) << "f" << std::endl;
	else
		std::cout << "float: overflow" << std::endl;
	std::cout << std::fixed <<std::setprecision(1) << "double: " << n << std::endl;
}
