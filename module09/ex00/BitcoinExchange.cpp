#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <exception>

static bool	dateIsCorrect(std::string &date) {
	int year, month, day;
	char c1, c2;
	if (date.length() != 10) {
		std::cerr << "Error: bad date format. => " << date << std::endl;
		return (false);
	}
	std::istringstream iss(date);
	iss >> std::noskipws >> year >> c1 >> month >> c2 >> day;
	if (iss.fail() || c1 != '-' || c2 != '-' || iss.peek() != EOF) {
		std::cerr << "Error: bad date format. => " << date << std::endl;
		return (false);
	}
	int	days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (!(year % 4) && ((year % 100) || !(year % 400)))
		days[2] = 29;
	if (year < 0 || month > 12 || month < 1 || day > days[month] || day < 1) {
		std::cerr << "Error: date out of range. => " << date << std::endl;
		return (false);
	}
	return (true);
}

static bool	checkLine(std::string &line, std::string del, std::pair<std::string, float> &entry, bool isDataBase) {
	size_t	delI = line.find(del);
	if (delI == std::string::npos) {
		std::cerr << "Error: bad input. => " << line << std::endl;
		return (false);
	}
	entry.first = line.substr(0, delI);
	if (!dateIsCorrect(entry.first))
		return (false);
	std::string	strFloat = line.substr(delI + del.length());
	size_t numI = strFloat.find_first_of("0123456789");
	if (numI == std::string::npos || !(numI == 0 || (numI == 1 && strFloat[0] == '-'))) {
		std::cerr << "Error: bad input. => " << line << std::endl;
		return (false);
	}
	std::istringstream	iss(strFloat);
	iss >> std::noskipws >> entry.second;
	if (iss.fail() || (!isDataBase && iss.peek() == EOF && entry.second > 1000)) {
		std::cerr << "Error: too large a number." << std::endl;
		return (false);
	}
	if (iss.peek() != EOF) {
		std::cerr << "Error: bad input. => " << line << std::endl;
		return (false);
	}
	if (entry.second < 0) {
		std::cerr << "Error: not a positive number." << std::endl;
		return (false);
	}
	return (true);
}

static bool getDelimCSV(std::string &line, std::string &delim)
{
	std::string::const_iterator it = line.begin();
	for (; it != line.end() && std::isalnum(*it); it++) ;
	if (it == line.begin())
		return (false);
	std::string::const_iterator ite = it;
	for (; ite != line.end() && !std::isalnum(*ite); ite++) ;
	if (ite == line.end() || ite == it)
		return (false);
	delim.assign(it, ite);
	return (true);
}

static bool getDataFromCSV(std::map<std::string, float> &data, const std::string &dataFile) {
	std::ifstream	file(dataFile.c_str());
	if (!file.is_open())
	{
		std::cout << "Error: could not open file." << std::endl;
		return (false);
	}
	std::string	line;
	std::pair<std::string, float>	entry;
	std::getline(file, line);
	std::string delim("");
	if (!getDelimCSV(line, delim) || delim.empty())
		return (std::cerr << "Bad CSV format:" << line << std::endl, false);
	if (!line.empty() && line[0] <= '9' && line[0] >= '0') {
		if (checkLine(line, delim, entry, true))
			data[entry.first] = entry.second;
	}
	while (std::getline(file, line)) {
		if (checkLine(line, delim, entry, true))
			data[entry.first] = entry.second;
	}
	return (true);
}

BitcoinExchange::BitcoinExchange() {
	if (!getDataFromCSV(this->_data, "data.csv"))
		throw std::exception();
}

BitcoinExchange::BitcoinExchange(std::string dataFile) {
	if (!getDataFromCSV(this->_data, dataFile))
		throw std::exception();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy) {
	this->_data = copy.getData();
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &copy) {
	if (this != &copy)
		this->_data = copy.getData();
	return (*this);
}

std::map<std::string, float>	BitcoinExchange::getData() const {
	return (this->_data);
}

void	BitcoinExchange::convert(std::string &line) const{
	std::pair<std::string, float>			entry;
	if (checkLine(line, " | ", entry, false)) {
		std::map<std::string, float>::const_iterator	it = this->_data.lower_bound(entry.first);
		if (it == this->_data.end() || it->first != entry.first) {
			if (it == this->_data.begin()) {
				std::cerr << "Error: to early. => " << entry.first << std::endl;
				return ;
			}
			--it;
		}
		std::cout << entry.first << " => " << entry.second << " = " << entry.second * it->second << std::endl;
	}
}

bool	BitcoinExchange::run(std::string fileName) const {
	std::ifstream	file(fileName.c_str());
	if (!file.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;
		return (false);
	}
	std::string	line;
	std::getline(file, line);
	if (!line.empty() && line[0] <= '9' && line[0] >= '0')
		this->convert(line);
	while (std::getline(file, line))
		this->convert(line);
	return (true);
}
