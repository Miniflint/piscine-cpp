#include "PmergeMe.hpp"
#include <vector>
#include <iostream>
#include <sstream>
#include <iomanip>

// unsigned int	lastLast = 0, last = 1;
// for (unsigned int i = 0; i < 42; i++) {
// 	unsigned int	actual = (lastLast * 2) + last;
// 	lastLast = last;
// 	last = actual;
// 	std::cout << actual << ", ";
// }

int	main(int ac, char **av)
{
	std::cout << std::endl;
	if (ac < 2)
	{
		std::cerr << "Error: not enought argument." << std::endl;
		return (1);
	}
	std::vector<unsigned int>	toSortVec;
	std::deque<unsigned int>	toSortDeque;
	double						timeVec, timeDeque;
	PmergeMe	fj;
	if (!fj.runFordJohnson(av, toSortVec, timeVec))
		return (1);
	if (!fj.runFordJohnson(av, toSortDeque, timeDeque))
		return (1);
	std::cout << "Before:\t";
	for (int i = 1; i < ac - 1; ++i) {
		std::cout << av[i] << " ";
	}
	std::cout << av[ac - 1] << "\nAfter:\t";
	for (std::deque<unsigned int>::const_iterator it = toSortDeque.begin(); it < toSortDeque.end() - 1; ++it) {
		std::cout << *it << " ";
	}
	std::cout << toSortDeque.back() << "\nTime to process a range of " << ac - 1 << " elements with std::vector : " << std::fixed << std::setprecision(5) << timeVec << " us";
	std::cout << "\nTime to process a range of " << ac - 1 << " elements with std::deque : " << std::fixed << std::setprecision(5) << timeDeque << " us" << std::endl;
	return (0);
}
