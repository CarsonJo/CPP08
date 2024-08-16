#include <vector>
#include <deque>
#include <list>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "Span.hpp"

void	test1()
{
	std::vector<int> b(0);
	Span<std::vector> a(100000);
	srand(time(NULL));
	for (int i = 0; i < 100000; i++)
		b.push_back(rand() % 1000000);
	try
	{
		a.addRange(b.begin(), b.end());
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << a.longestSpan() << " " << a.shortestSpan() << std::endl;
}

void	test2()
{
	Span<std::deque> sp = Span<std::deque>(5);

	try
	{
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << sp.longestSpan() << " " << sp.shortestSpan() << std::endl;
}

int main()
{
	test1();
	test2();
}
