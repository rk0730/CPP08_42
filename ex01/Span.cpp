#include "Span.hpp"
#include <iterator>
#include <limits>

Span::Span() : _size(0), _count(0), _shortestSpan(std::numeric_limits<unsigned int>::max())
{
}

Span::Span(unsigned int N)
	: _size(N), _count(0), _shortestSpan(std::numeric_limits<unsigned int>::max())
{
}

Span::Span(const Span &other)
	: _size(other._size), _count(other._count), _data(other._data),
	  _shortestSpan(other._shortestSpan)
{
}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		_size = other._size;
		_count = other._count;
		_data = other._data;
		_shortestSpan = other._shortestSpan;
	}
	return *this;
}

Span::~Span()
{
}

void Span::addNumber(int number)
{
	if (_count >= _size)
	{
		throw SpanFullException();
	}
	_data[number]++;
	_count++;
	// 同じ数が追加されたらshortestSpanは0にする
	if (_data[number] > 1)
		_shortestSpan = 0;
	std::map<int, int>::iterator it = _data.find(number);
	if (it != _data.begin())
	{
		// 前の要素とのspanを計算して_shortestSpanを更新
		std::map<int, int>::iterator prev_it = it;
		prev_it--;
		unsigned int span = number - prev_it->first;
		_shortestSpan = std::min(_shortestSpan, span);
	}
	std::map<int, int>::iterator next_it = it;
	next_it++;
	if (next_it != _data.end())
	{
		// 次の要素とのspanを計算して_shortestSpanを更新
		unsigned int span = next_it->first - number;
		_shortestSpan = std::min(_shortestSpan, span);
	}
}

unsigned int Span::shortestSpan() const
{
	if (_count < 2)
		throw SpanTooShortException();
	return _shortestSpan;
}

unsigned int Span::longestSpan() const
{
	if (_count < 2)
		throw SpanTooShortException();
	return _data.rbegin()->first - _data.begin()->first;
}

const char *Span::SpanFullException::what() const throw()
{
	return "Span is full";
}

const char *Span::SpanTooShortException::what() const throw()
{
	return "Span is too short to calculate a span";
}
