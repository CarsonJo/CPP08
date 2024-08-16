#ifndef SPAN_HPP
# define SPAN_HPP
#include <vector>
#include <exception>
#include <iterator>
#include <algorithm>
#include <limits>
template <template<typename = int, typename = std::allocator<int> >class A>
class Span
{
	public :
		class full : public std::exception
		{
			public :
				const char * what() const throw();
		};
		Span(int number);
		Span(const Span &to_copy);
		~Span();

		void			addRange(typename A<>::iterator a, typename A<>::iterator b);
		void			addNumber(int number);
		unsigned int	shortestSpan() const throw();
		unsigned int	longestSpan() const throw();

	private :
		A<>				arr;
		Span();
		unsigned int		size;
		unsigned int	shortest_span;
};
#include "Span.tpp"
#endif