#include "../headers/INC.hpp"

void SEARCH(PhoneBook *pb, int amount)
{
	int	_enterIndex;

	pb->printInfos(amount);
	Log_n("Enter the index");
	Log(">> ");
	std::cin >> _enterIndex;
	pb->specSearch(_enterIndex);
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
		}
		else if (_whatToDo == "SEARCH") {
			SEARCH(&pb, amount);
		}
		else if (_whatToDo == "EXIT") {
			exit(EXIT_SUCCESS);
		}
		else {
			x--;
			amount--;
		}
		x++;
		amount++;
		Log_n("\n");
	}
	return (0);
}
