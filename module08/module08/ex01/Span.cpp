#include "Span.hpp"
#include <iostream>
#include <limits>
#include <algorithm>
#include <functional>

Span::Span() : _sizet(0), _span_max(0), _span_min(std::numeric_limits<int>::max()), _spansIsSet(false) {}

Span::Span(unsigned int sizet) : _sizet(sizet), _span_max(0), _span_min(std::numeric_limits<int>::max()), _spansIsSet(false) {}

Span::Span(const Span &src) : _sizet(src.get_sizet()), _span_max(0), _span_min(std::numeric_limits<int>::max()), _spansIsSet(false)
{
	std::vector<int> src_t = src.get_t();
	this->addNumber(src_t.begin(), src_t.end());
}

Span &Span::operator=(const Span &src)
{
	if (this == &src)
		return (*this);
	this->_span_max = 0;
	this->_span_min = std::numeric_limits<int>::max();
	std::vector<int> src_t = src.get_t();
	this->_t.clear();
	this->addNumber(src_t.begin(), src_t.end());
	return (*this);
}

Span::~Span() {}

unsigned int	Span::get_sizet(void) const
{
	return (this->_sizet);
}

const std::vector<int>	&Span::get_t(void) const
{
	return (this->_t);
}

void 	Span::addNumber(int t)
{
	if (this->_t.size() + 1 > this->_sizet)
		throw TooMuchIntegerException();
	this->_spansIsSet = false;
	this->_t.push_back(t);
}

void	Span::_get_spans(void)
{
	if (this->_spansIsSet)
		return ;
	this->_spansIsSet = true;
	this->_span_min = std::numeric_limits<int>::max();
	this->_span_max = 0;
	std::sort(this->_t.begin(), this->_t.end());
	std::vector<int>::iterator it = this->_t.begin();
	std::vector<int>::iterator it_end = this->_t.end();
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

void	Span::print_vector(void)
{
	std::cout << "=========== PRINTING ===========" << std::endl;
	std::vector<int>::iterator it = this->_t.begin();

	for (; it != this->_t.end(); it++)
		std::cout << *it << std::endl;
}

int	Span::shortestSpan()
{
	if (this->_t.size() < 2)
		throw NoSpanException();
	this->_get_spans();
	return (this->_span_min);
}
int	Span::longestSpan()
{
	if (this->_t.size() < 2)
		throw NoSpanException();
	this->_get_spans();
	return (this->_span_max);
}