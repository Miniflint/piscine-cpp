#include "Span.hpp"
#include <iostream>

Span::Span() : _sizet(0), _span_max(0), _span_min(0b01111111111111111111111111111111) {}

Span::Span(unsigned int sizet) : _sizet(sizet), _span_max(0), _span_min(0b01111111111111111111111111111111) {}
Span::Span(const Span &src) : _sizet(src.get_sizet()), _span_max(0), _span_min(0b01111111111111111111111111111111)
{
	std::list<int> src_t = src.get_t();
	this->addNumber(src_t.begin(), src_t.end());
}

Span &Span::operator=(const Span &src)
{
	if (this == &src)
		return (*this);
	this->_span_max = 0;
	this->_span_min = 0b01111111111111111111111111111111;
	std::list<int> src_t = src.get_t();
	this->_t.clear();
	this->addNumber(src_t.begin(), src_t.end());
	return (*this);
}

Span::~Span()
{}

unsigned int	Span::get_sizet(void) const
{
	return (this->_sizet);
}

std::list<int>	Span::get_t(void) const
{
	return (this->_t);
}

void 	Span::addNumber(std::list<int>::iterator begin, std::list<int>::iterator end)
{
	const unsigned int dist = std::distance(begin, end);
	if (dist + this->_t.size() > this->_sizet)
		throw TooMuchIntegerException();
	this->_t.insert(this->_t.end(), begin, end);
	this->_t.sort();
	this->_get_spans();
}

void 	Span::addNumber(int t)
{
	if (this->_t.size() + 1 > this->_sizet)
		throw TooMuchIntegerException();
	this->_t.insert(std::upper_bound( this->_t.begin(), this->_t.end(), t ), t);
	this->_get_spans();
}

void	Span::_get_spans(void)
{
	if (this->_t.size() < 2)
		return ;
	std::list<int>::iterator it = this->_t.begin();
	std::list<int>::iterator it_end = this->_t.end();
	int	tmp = *(--it_end);

	this->_span_max = tmp - *(this->_t.begin());
	tmp = *it;
	it++;
	for (; it != this->_t.end(); it++)
	{
		if (*it - tmp < this->_span_min)
			this->_span_min = *it - tmp;
		tmp = *it;
	}
}

void	Span::print_list(void)
{
	std::cout << "=========== PRINTING ===========" << std::endl;
	std::list<int>::iterator it = this->_t.begin();

	for (; it != this->_t.end(); it++)
		std::cout << *it << std::endl;
}

int	Span::shortestSpan() const
{
	if (this->_t.size() < 2)
		throw NoSpanException();
	return (this->_span_min);
}
int	Span::longestSpan() const
{
	if (this->_t.size() < 2)
		throw NoSpanException();
	return (this->_span_max);
}