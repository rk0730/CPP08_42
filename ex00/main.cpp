#include "easyfind.hpp"
#include <iostream>
#include <list>
#include <vector>

int main()
{
	std::vector<int> vec(5);
	for (int i = 0; i < 5; ++i)
		vec[i] = i + 1; // Fill vector with values 1 to 5
	std::vector<int>::iterator it = easyfind(vec, 3);
	if (it != vec.end())
		std::cout << "Found: " << *it << std::endl;
	else
		std::cout << "Not found" << std::endl;

	std::vector<int>::iterator it2 = easyfind(vec, 10);
	if (it2 != vec.end())
		std::cout << "Found: " << *it2 << std::endl;
	else
		std::cout << "Not found" << std::endl;

	std::list<int> lst;
	for (int i = 0; i < 5; ++i)
		lst.push_back(i + 1); // Fill list with values 1 to 5
	std::list<int>::iterator it3 = easyfind(lst, 2);
	if (it3 != lst.end())
		std::cout << "Found: " << *it3 << std::endl;
	else
		std::cout << "Not found" << std::endl;
	std::list<int>::iterator it4 = easyfind(lst, 6);
	if (it4 != lst.end())
		std::cout << "Found: " << *it4 << std::endl;
	else
		std::cout << "Not found" << std::endl;
	return 0;
}
