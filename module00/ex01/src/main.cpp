#include "../headers/INC.hpp"
#include <cstdlib>


void SEARCH(PhoneBook *pb, int amount)
{
	std::string	_enterIndex;
	int			realIndex;

	if (amount == 0)
	{
		Log("No contact yet");
		return ;
	}
	pb->printInfos(amount);
	Log_n("Enter the index");
	Log(">> ");
	std::cin >> _enterIndex;
	try {
		realIndex = std::stoi(_enterIndex);
	}
	catch (const std::invalid_argument) {
		Log_n("Tu te crois drole ???????");
		exit(EXIT_FAILURE);
	}
	pb->specSearch(realIndex);
}


int	main()
{
	PhoneBook	pb;
	std::string	_whatToDo;
	int			x;
	int			amount;
	
	x = 0;
	amount = 0;
	while (1)
	{
		if (x > MAX_SIZE - 1) {
			x = 0;
		}
		Log_n("Choose an option");
		Log_n("ADD\nSEARCH\nEXIT");
		Log(">> ");
		std::cin >> _whatToDo;
		if (_whatToDo == "ADD") {
			pb.addContact(x);
			x++;
			amount++;
		}
		else if (_whatToDo == "SEARCH") {
			SEARCH(&pb, amount);
		}
		else if (_whatToDo == "EXIT") {
			exit(EXIT_SUCCESS);
		}
		Log_n("\n");
	}
	return (0);
}
