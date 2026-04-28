#ifndef SPAN_HPP
# define SPAN_HPP

# include <algorithm>
# include <vector>

class Span
{
	public:
		Span();
		Span(unsigned int sizet);
		Span(const Span &src);
		Span &operator=(const Span &src);
		~Span();

	private:
		unsigned int	_sizet;
		std::vector<int>	_t;
};

#endif