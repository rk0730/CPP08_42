#ifndef SPAN_HPP
#define SPAN_HPP

#include <map>

class Span
{
public:
	Span();
	Span(unsigned int N);
	Span(const Span &other);
	Span &operator=(const Span &other);
	~Span();

	void addNumber(int number);
	template <typename T> void addNumbers(T &container)
	{
		if (_count + container.size() > _size)
			throw SpanFullException();
		for (typename T::iterator it = container.begin(); it != container.end(); ++it)
			addNumber(*it);
	}
	unsigned int shortestSpan() const;
	unsigned int longestSpan() const;

	class SpanFullException : public std::exception
	{
	public:
		const char *what() const throw();
	};
	class SpanTooShortException : public std::exception
	{
	public:
		const char *what() const throw();
	};

private:
	unsigned int _size;
	unsigned int _count;
	std::map<int, int> _data;
	unsigned int _shortestSpan;
};

#endif
