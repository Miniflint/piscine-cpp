#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP
# include <string>
# include <map>

class BitcoinExchange {
	public:
		BitcoinExchange();
		BitcoinExchange(std::string dataFile);
		BitcoinExchange(const BitcoinExchange &copy);
		~BitcoinExchange();
		BitcoinExchange	&operator=(const BitcoinExchange &copy);
		std::map<std::string, float>	getData() const;
		void	convert(std::string &line) const;
		bool	run(std::string fileName) const;
	private:
		std::map<std::string, float>	_data;
};

#endif