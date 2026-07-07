#include "PmergeMe.hpp"
#include <sys/time.h>
#include <sstream>
#include <iostream>

const unsigned int	PmergeMe::_jacobsthal[] = { JACOBSTHAL };
const unsigned int	PmergeMe::_jacobsthalLength = sizeof(PmergeMe::_jacobsthal) / sizeof(PmergeMe::_jacobsthal[0]);

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &copy) {
	(void)copy;
}

PmergeMe::~PmergeMe() {}

PmergeMe	&PmergeMe::operator=(const PmergeMe &copy) {
	(void)copy;
	return (*this);
}

static double	getTime() {
	struct timespec time;
	clock_gettime(CLOCK_MONOTONIC, &time);
	return (static_cast<double>(time.tv_sec) * 1000000.0) + (static_cast<double>(time.tv_nsec) / 1000.0);
}

static bool	strsToUnsigned(char **strs, std::vector<unsigned int> &vec) {
	unsigned int	n;
	for (unsigned int i = 1; strs[i]; ++i) {
		if (!strs[i][0] || strs[i][0] == '-') {
			std::cerr << "Error: invalid value => '" << strs[i] << "'" << std::endl;
			return (false);
		}
		std::istringstream	iss(strs[i]);
		iss >> std::noskipws >> n;
		if (iss.fail() || !iss.eof()) {
			std::cerr << "Error: invalid value => '" << strs[i] << "'" << std::endl;
			return (false);
		}
		vec.push_back(n);
	}
	return (true);
}

void	binaryInsert(std::vector<unsigned int> &mainChain, std::vector<unsigned int>::const_iterator loser, size_t lenght, unsigned int chunkSize) {
	size_t			start = 0, mid;
	while (start < lenght) {
		mid = start + (lenght - start) / 2;
		if (*loser > mainChain[mid * chunkSize])
			start = mid + 1;
		else
			lenght = mid;
	}
	mainChain.insert(mainChain.begin() + start * chunkSize, loser, loser + chunkSize);
}

void	PmergeMe::_jacobsthalInsert(std::vector<unsigned int> &toSort, std::vector<unsigned int> &mainChain, unsigned int chunkSize, unsigned int chunkSizeX2) const {
	size_t	group = 0;
	unsigned int	lastJacob = 1, actualJacob;
	size_t			searchSection, mainChainSize = 0, toSortSizeX2 = toSort.size() / chunkSizeX2, toSortSize = toSort.size() / chunkSize;
	while (mainChainSize < toSortSize) {
		mainChainSize = mainChain.size() / chunkSize;
		if (group >= this->_jacobsthalLength || this->_jacobsthal[++group] > toSortSizeX2) {
			actualJacob = toSortSizeX2;
			searchSection = mainChainSize;
		} else {
			actualJacob = this->_jacobsthal[group];
			searchSection = (1 << (group + 1)) - 1;
			if (searchSection > mainChainSize)
				searchSection = mainChainSize;
		}
		size_t	i = actualJacob;
		while (i > lastJacob)
			binaryInsert(mainChain, toSort.begin() + (--i * chunkSizeX2) + chunkSize, searchSection, chunkSize);
		lastJacob = actualJacob;
	}
}

void PmergeMe::fordJohnson(std::vector<unsigned int> &toSort, unsigned int depth) {
	unsigned int	chunkSize = 1 << depth;
	unsigned int	chunkSizeX2 = chunkSize << 1;
	if (toSort.size() < chunkSizeX2)
		return;
	std::vector<unsigned int>	orphan;
	if (toSort.size() % chunkSizeX2) {
		orphan.assign(toSort.end() - chunkSize, toSort.end());
		toSort.erase(toSort.end() - chunkSize, toSort.end());
	}
	size_t i = 0;
	while (i + chunkSizeX2 <= toSort.size()) {
		if (toSort[i] < toSort[i + chunkSize])
			std::swap_ranges(toSort.begin() + i, toSort.begin() + i + chunkSize, toSort.begin() + i + chunkSize);
		i += chunkSizeX2;
	}
	this->fordJohnson(toSort, depth + 1);
	std::vector<unsigned int>	mainChain(toSort.begin() + chunkSize, toSort.begin() + chunkSizeX2);
	for (size_t i = 0; i < toSort.size(); i += chunkSizeX2)
		mainChain.insert(mainChain.end(), toSort.begin() + i, toSort.begin() + i + chunkSize);
	this->_jacobsthalInsert(toSort, mainChain, chunkSize, chunkSizeX2);
	if (!orphan.empty())
		binaryInsert(mainChain, orphan.begin(), mainChain.size() / chunkSize, chunkSize);
	toSort.swap(mainChain);
}

bool		PmergeMe::runFordJohnson(char **strs, std::vector<unsigned int> &toSort, double &time) {
	double	startTime = getTime();
	if (!strsToUnsigned(strs, toSort))
		return (false);
	this->fordJohnson(toSort, 0);
	time = getTime() - startTime;
	return (true);
}

//---------------------DEQUE-----------------------//

static bool	strsToUnsigned(char **strs, std::deque<unsigned int> &vec) {
	unsigned int	n;
	for (unsigned int i = 1; strs[i]; ++i) {
		if (!strs[i][0] || strs[i][0] == '-') {
			std::cerr << "Error: invalid value => '" << strs[i] << "'" << std::endl;
			return (false);
		}
		std::istringstream	iss(strs[i]);
		iss >> std::noskipws >> n;
		if (iss.fail() || !iss.eof()) {
			std::cerr << "Error: invalid value => '" << strs[i] << "'" << std::endl;
			return (false);
		}
		vec.push_back(n);
	}
	return (true);
}

void	binaryInsert(std::deque<unsigned int> &mainChain, std::deque<unsigned int>::const_iterator loser, size_t lenght, unsigned int chunkSize) {
	size_t			start = 0, mid;
	while (start < lenght) {
		mid = start + (lenght - start) / 2;
		if (*loser > mainChain[mid * chunkSize])
			start = mid + 1;
		else
			lenght = mid;
	}
	mainChain.insert(mainChain.begin() + start * chunkSize, loser, loser + chunkSize);
}

void	PmergeMe::_jacobsthalInsert(std::deque<unsigned int> &toSort, std::deque<unsigned int> &mainChain, unsigned int chunkSize, unsigned int chunkSizeX2) const {
	size_t	group = 0;
	unsigned int	lastJacob = 1, actualJacob;
	size_t			searchSection, mainChainSize = 0, toSortSizeX2 = toSort.size() / chunkSizeX2, toSortSize = toSort.size() / chunkSize;
	while (mainChainSize < toSortSize) {
		mainChainSize = mainChain.size() / chunkSize;
		if (group >= this->_jacobsthalLength || this->_jacobsthal[++group] > toSortSizeX2) {
			actualJacob = toSortSizeX2;
			searchSection = mainChainSize;
		} else {
			actualJacob = this->_jacobsthal[group];
			searchSection = (1 << (group + 1)) - 1;
			if (searchSection > mainChainSize)
				searchSection = mainChainSize;
		}
		size_t	i = actualJacob;
		while (i > lastJacob)
			binaryInsert(mainChain, toSort.begin() + (--i * chunkSizeX2) + chunkSize, searchSection, chunkSize);
		lastJacob = actualJacob;
	}
}

void PmergeMe::fordJohnson(std::deque<unsigned int> &toSort, unsigned int depth) {
	unsigned int	chunkSize = 1 << depth;
	unsigned int	chunkSizeX2 = chunkSize << 1;
	if (toSort.size() < chunkSizeX2)
		return;
	std::deque<unsigned int>	orphan;
	if (toSort.size() % chunkSizeX2) {
		orphan.assign(toSort.end() - chunkSize, toSort.end());
		toSort.erase(toSort.end() - chunkSize, toSort.end());
	}
	size_t i = 0;
	while (i + chunkSizeX2 <= toSort.size()) {
		if (toSort[i] < toSort[i + chunkSize])
			std::swap_ranges(toSort.begin() + i, toSort.begin() + i + chunkSize, toSort.begin() + i + chunkSize);
		i += chunkSizeX2;
	}
	this->fordJohnson(toSort, depth + 1);
	std::deque<unsigned int>	mainChain(toSort.begin() + chunkSize, toSort.begin() + chunkSizeX2);
	for (size_t i = 0; i < toSort.size(); i += chunkSizeX2)
		mainChain.insert(mainChain.end(), toSort.begin() + i, toSort.begin() + i + chunkSize);
	this->_jacobsthalInsert(toSort, mainChain, chunkSize, chunkSizeX2);
	if (!orphan.empty())
		binaryInsert(mainChain, orphan.begin(), mainChain.size() / chunkSize, chunkSize);
	toSort.swap(mainChain);
}

bool		PmergeMe::runFordJohnson(char **strs, std::deque<unsigned int> &toSort, double &time) {
	double	startTime = getTime();
	if (!strsToUnsigned(strs, toSort))
		return (false);
	this->fordJohnson(toSort, 0);
	time = getTime() - startTime;
	return (true);
}