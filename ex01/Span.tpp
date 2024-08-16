template <template<typename = int, typename = std::allocator<int> >class A>
Span<A>::Span(int number) : arr(0), size(number), shortest_span(std::numeric_limits<unsigned int>::max())
{

}

template <template<typename = int, typename = std::allocator<int> >class A>
Span<A>::Span(const Span<A> &to_copy) : arr(to_copy.arr), size(to_copy.size), shortest_span(to_copy.shortest_span)
{

}

template <template<typename = int, typename = std::allocator<int> >class A>
void	Span<A>::addRange(typename A<>::iterator a,typename A<>::iterator b)
{
	if (arr.size() + std::distance(a, b) > size)
		throw(full());
	while (a != b)
	{
		addNumber(*a);
		a++;
	}
}

template <template<typename = int, typename = std::allocator<int> >class A>
Span<A>::~Span()
{

}

template <template<typename = int, typename = std::allocator<int> >class A>
void	Span<A>::addNumber(int number)
{
	if (arr.size() + 1 > size)
		throw(full());
	if (arr.empty())
		arr.push_back(number);
	else
	{
		typename A<>::iterator i = arr.insert(std::upper_bound(arr.begin(), arr.end(), number), number);
		typename A<>::iterator j = i;
		if (i != arr.begin())
		{
			if (labs(*i - *(--j)) < shortest_span)
				shortest_span = labs(*i - *j);
			j++;
		}
		if (i != (--arr.end()) && labs(*i - *(++j)) < shortest_span)
			shortest_span = labs(*i - *j);
	}
}

template <template<typename = int, typename = std::allocator<int> >class A>
unsigned int	Span<A>::shortestSpan() const throw()
{
	if (arr.empty() || arr.size() == 1)
		return (0);
	return (shortest_span);
}

template <template<typename = int, typename = std::allocator<int> >class A>
unsigned int	Span<A>::longestSpan() const throw()
{
	if (arr.empty() || arr.size() == 1)
		return (0);
	return (*(--arr.end()) - *arr.begin());
}

template <template<typename = int, typename = std::allocator<int> >class A>
const char *Span<A>::full::what() const  throw()
{
	return ("the span will overflow!");
}