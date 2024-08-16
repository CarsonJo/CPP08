#ifndef EASY_FIND_HPP
# define EASY_FIND_HPP

template<typename A>
typename A::iterator	easyfind(A &arr, int second)
{
	typename A::iterator it = arr.begin();

	while (it != arr.end())
	{
		if (*it == second)
		{
			std::cout << "found it" << std::endl;
			return (it);
		}
		it++;
	}
	std::cout << "didn't found it" << std::endl;
	return (arr.end());
}
#endif