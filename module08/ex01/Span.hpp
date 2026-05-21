#ifndef SPAN_HPP
# define SPAN_HPP

# include <algorithm>
# include <vector>
# include <list>

class Span
{
	public:
		Span();
		Span(unsigned int sizet);
		Span(const Span &src);
		Span &operator=(const Span &src);
		int				smallestSpan() const;
		int				longestSpan() const;
		unsigned int	get_sizet(void) const;
		std::list<int>	get_t(void) const;
		void			print_list(void);

		void addNumber(int t);
		void addNumber(std::list<int>::iterator begin, std::list<int>::iterator end);
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
					return ("No span can be found. list < 2 int");
				}
		};
		~Span();

	private:
		unsigned int	_sizet;
		int				_span_max;
		int				_span_min;
		std::list<int>	_t;
		void			_get_spans(void);
};

#endif