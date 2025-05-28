#include "harl.hpp"

Harl::Harl(void)
{
    this->_s[0].str = "debug";
    this->_s[0].f = &Harl::_debug;
    this->_s[1].str = "info";
    this->_s[1].f = &Harl::_info;
    this->_s[2].str = "warning";
    this->_s[2].f = &Harl::_warning;
    this->_s[3].str = "error";
    this->_s[3].f = &Harl::_error;
    return ;
}

void Harl::_debug(void)
{
    std::cout << "[DEBUG]" << std::endl;
}

void Harl::_info(void)
{
    std::cout << "[INFO]" << std::endl;
}

void Harl::_warning(void)
{
    std::cout << "[WARNING]" << std::endl;
}

void Harl::_error(void)
{
    std::cout << "[ERROR]" << std::endl;
}

void    lowered(std::string &s)
{
    int i = 0;

    while (s[i])
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
            s[i] += 32;
        i++;
    }
}

void Harl::complain(std::string level)
{
    int max_lvl = 0;

    lowered(level);
    while (max_lvl <= 3)
    {
        if (level == this->_s[max_lvl].str)
            break ;
        max_lvl++;
    }
    switch (max_lvl) {
		case 0:
			(this->*(_s[0].f))();
			break ;
		case 1:
			(this->*(_s[0].f))();
			(this->*(_s[1].f))();
			break ;
		case 2:
			(this->*(_s[0].f))();
			(this->*(_s[1].f))();
			(this->*(_s[2].f))();
			break ;
		case 3:
			(this->*(_s[0].f))();
			(this->*(_s[1].f))();
			(this->*(_s[2].f))();
			(this->*(_s[3].f))();
			break ;
		default:
		    std::cout << "This level does not exist" << std::endl;
        	break ;

    }
}
