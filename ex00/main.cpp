#include <algorithm>
#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <map>
#include <set>
#include <string>
#include "easyfind.hpp"

int main()
{
	const int								test[3] = {0,1,2};
	std::vector<int>						a(test, test + 3);
	std::deque<int>							b(test, test + 3);
	std::list<int>							c(test, test + 3);

	std::cout << *easyfind<std::vector<int> >(a, 1) << std::endl;
	std::cout << *easyfind<std::deque<int> >(b, 2) << std::endl;
	std::cout << *easyfind<std::list<int> >(c, 1) << std::endl;
}