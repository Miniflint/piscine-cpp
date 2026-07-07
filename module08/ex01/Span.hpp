#ifndef SPAN_HPP
# define SPAN_HPP

# include <algorithm>
# include <vector>
# include <list>
# include <iterator>

class Span
{
	public:
		Span();
		Span(unsigned int sizet);
		Span(const Span &src);
		Span &operator=(const Span &src);
		int						shortestSpan();
		int						longestSpan();
		unsigned int			get_sizet(void) const;
		const std::vector<int>	&get_t(void) const;
		void					print_vector(void);
		void 					addNumber(int t);
		template<typename T>
		void 					addNumber(T begin, T end);
		class TooMuchIntegerException : public std::exception
		{
			public:
				virtual char const *what() const throw()
				{
					return ("Cannot add more element(s), it would exceed maximum");
				}
		};
		class NoSpanException : public std::exception
		{
			public:
				virtual char const *what() const throw()
				{
					return ("No span can be found. vector < 2 int");
				}
		};
		~Span();

	private:
		unsigned int		_sizet;
		int					_span_max;
		int					_span_min;
		std::vector<int>	_t;
		void				_get_spans(void);
		bool				_spansIsSet;
};

template<typename T>
void 	Span::addNumber(T begin, T end)
{
	const unsigned int dist = std::distance(begin, end);
	if (dist + this->_t.size() > this->_sizet)
		throw TooMuchIntegerException();
	if (begin != end) {
		this->_t.insert(this->_t.end(), begin, end);
		this->_spansIsSet = false;
	}
}

#endif