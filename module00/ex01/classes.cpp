#include "main.class.hpp"

Contact::Contact(void)
{
	this->_index = -1;
	this->_firstName = "";
	this->_lastName = "";
	this->_nickName = "";
	this->_phoneNumber = "";
	this->_darkestSecret = "";
	return ;
}

Contact::~Contact(void)
{
	return ;
}

void	Contact::addContact(
	int	index, std::string firstName,
	std::string lastName, std::string nickName,
	std::string phoneNumber,std::string darkestSecret
)
{
	this->_index = index;
	this->_firstName = firstName;
	this->_lastName = lastName;
	this->_nickName = nickName;
	this->_phoneNumber = phoneNumber;
	this->_darkestSecret = darkestSecret;
	return ;
}

void	PRINT(std::string str)
{
	if (str.length() < 10) {
		std::cout << str << std::setfill(' ') << std::setw(WIDTH - str.length() + 1) << "|";
	}
	else {
		std::cout << str.substr(0, 7) << "..." << "|";
	}
}

void PRINT_INT(int x)
{
	std::cout << "|" << x << std::setfill(' ') << std::setw(WIDTH - 1) << "|";
}

void	Contact::printContact(void)
{
	if (this->_index == -1)
		return ;
	PRINT_INT(this->_index);
	PRINT(this->_firstName);
	PRINT(this->_lastName);
	PRINT(this->_nickName);
	std::cout << std::endl;
}

void Contact::printInfo(void)
{
	if (this->_index == -1)
		return ;
	std::cout << this->_firstName << std::endl;
	std::cout << this->_lastName << std::endl;
	std::cout << this->_nickName << std::endl;
	std::cout << this->_phoneNumber << std::endl;
	std::cout << this->_darkestSecret << std::endl;
}

PhoneBook::PhoneBook(void)
{
	this->_amountPeople = 0;
	return ;
}

PhoneBook::~PhoneBook(void)
{
	return ;
}

void	PhoneBook::addContact(void)
{
	std::string	firstName;
	std::string	lastName;
	std::string	nickName;
	std::string	phoneNumber;
	std::string	darkestSecret;

	ASK("Enter a first name", firstName);
	ASK("Enter a last name", lastName);
	ASK("Enter a nick name", nickName);
	ASK("Enter a phoneNumber", phoneNumber);
	ASK("Enter the darkest Secret", darkestSecret);

	_contact[_amountPeople % maxSize].addContact(
		_amountPeople % maxSize, firstName,
		lastName, nickName,
		phoneNumber, darkestSecret);
	this->_amountPeople += 1;
}

void	PhoneBook::printAll(void)
{
	int	i;

	i = -1;
	while (++i < maxSize)
		this->_contact[i].printContact();
	return ;
}

void	PhoneBook::search(void)
{
	std::string	sIndex;
	int			rIndex;

	if (this->_amountPeople < 1)
		return ;
	this->printAll();
	std::cout << "Choisisez un contact: " << std::endl << ">> ";
	std::cin >> sIndex;
	rIndex = std::atoi(sIndex.c_str());
	if (rIndex < maxSize && rIndex >= 0)
		this->_contact[rIndex].printInfo();
	return ;
}