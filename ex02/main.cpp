#include "MutantStack.hpp"
#include <iostream>
#include <list>


int main()
{
	MutantStack<int> mstack;
	if (mstack.empty())
	{
		std::cout << "MutantStack is empty." << std::endl;
	}
	else
	{
		std::cout << "MutantStack is not empty." << std::endl;
	}
	mstack.push(5);
	mstack.push(17);
	std::cout << "Top element: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "Size after pop: " << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	std::cout << "MutantStack contents: ";
	for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	// MutankStackからstackを作成
	std::stack<int> s(mstack);

	// 同様の動作をstd::listでテスト
	std::list<int> lst;
	lst.push_back(5);
	lst.push_back(17);
	lst.pop_back();
	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	lst.push_back(0);

	std::cout << "List contents: ";
	for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	return 0;
}
