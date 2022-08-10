#include "../headers/INC.hpp"
#include <cmath>

PhoneBook::PhoneBook(void)
{
	PhoneBook::__init__();
	return ;
}

PhoneBook::~PhoneBook(void)
{
	return ;
}

int	PhoneBook::__init__(void)
{
	_amountContact = 0;
	if (_amountContact)
		return (1);
	return (0);
}

void	PhoneBook::addContact(int	x)
{
	std::string	firstName;
	std::string	lastName;
	std::string	nickname;

	Log("Enter the first name: ");
	std::cin.ignore(100, '\n');
	getline (std::cin, firstName);
	Log("\nEnter the last name: ");
	getline (std::cin, lastName);
	Log("\nEnter the nickname: ");
	getline (std::cin, nickname);

	_contact[x].addPerson(x, firstName, lastName, nickname);
	_amountContact++;
}

void	PhoneBook::printInfos(int index)
{
	int	x;

	x = 0;
	if (index > MAX_SIZE - 1) {
		index = MAX_SIZE - 1;
	}
	while (x < index)
	{
		_contact[x].printAllInfo();
		x++;
	}
}

void	PhoneBook::specSearch(int x)
{
	_contact[x].printSpecInfo();
}
