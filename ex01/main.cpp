#include "Span.hpp"
#include <cstdlib>
#include <iostream>
#include <vector>

int main(void)
{
	Span sp(5);
	sp.addNumber(6);
	try
	{
		std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "longest span: " << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "longest span: " << sp.longestSpan() << std::endl;

	try
	{
		sp.addNumber(11);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "Testing with a large number of elements" << std::endl;
	Span sp2 = Span(100000);
	std::vector<int> v;
	std::srand(time(NULL));
	for (int i = 0; i < 100000; i++)
	{
		int random_int = rand() % 1000000;
		v.push_back(random_int);
	}
	try
	{
		sp2.addNumbers(v);
		std::cout << "shortest span: " << sp2.shortestSpan() << std::endl;
		std::cout << "longest span: " << sp2.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}
