#include "../headers/INC.hpp"


#define PRINT_INT(x) std::cout << "|" << x << std::setfill(' ') << std::setw(WIDTH - 1) << "|"

Contact::Contact(void)
{
	return ;
}

Contact::~Contact(void)
{
	return ;
}

void	Contact::addPerson(
				int index,
				std::string firstName,
				std::string lastName,
				std::string nickname,
				std::string	phoneNumber,
				std::string	darkestSecret
		)
{
	this->_index = index;
	this->_firstName = firstName;
	this->_lastName = lastName;
	this->_nickName = nickname;
	this->_phoneNumber = phoneNumber;
	this->_darkestSecret = darkestSecret;
}

void	PRINT(std::string str)
{
	if (ft_strlen(str) < 10) {
		std::cout << str << std::setfill(' ') << std::setw(WIDTH - ft_strlen(str) + 1) << "|";
	}
	else {
		std::cout << str.substr(0, 7) << "..." << "|";
	}
}

void	Contact::printAllInfo(void)
{
	PRINT_INT(this->_index);
	PRINT(this->_firstName);
	PRINT(this->_lastName);
	PRINT(this->_nickName);
	std::cout << std::endl;
}

void	Contact::printSpecInfo(void)
{
	std::cout << std::setfill('=') << std::setw(WIDTH * 4) << std::endl;
	Log_n("");
	Log_n(this->_index);
	Log_n(this->_firstName);
	Log_n(this->_lastName);
	Log_n(this->_nickName);
	Log_n(this->_phoneNumber);
	Log_n(this->_darkestSecret);
	std::cout << std::setfill('=') << std::setw(WIDTH * 4);
}
