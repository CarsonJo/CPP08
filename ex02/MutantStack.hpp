#ifndef MutantStack_hpp
# define MutantStack_hpp
# include <memory>
# include <stack>
# include <deque>
# include <iterator>

template <typename A, typename B = std::deque<A> >
class MutantStack : public std::stack<A, B>
{
	public :
		MutantStack();
		MutantStack(typename B::iterator a, typename B::iterator b);
		MutantStack(const MutantStack<A, B> &to_copy);
		~MutantStack();

		typedef	typename B::iterator	iterator;

		typename B::iterator	begin();
		typename B::iterator	end();
	private :
		void	operator=(const MutantStack<A, B> &to_copy);
};

template <typename A, typename B>
MutantStack<A, B>::MutantStack() : std::stack<A, B>()
{

}

template <typename A, typename B>
MutantStack<A, B>::MutantStack(const MutantStack &to_copy) : std::stack<A, B>(to_copy)
{

}

template <typename A, typename B>
MutantStack<A, B>::MutantStack(typename B::iterator a, typename B::iterator b)
{
	while (a != b)
	{
		this->push(*a);
		a++;
	}
}

template <typename A, typename B>
MutantStack<A, B>::~MutantStack()
{

}

template <typename A, typename B>
typename B::iterator	MutantStack<A, B>::begin()
{
	return (this->c.begin());
}

template <typename A, typename B>
typename B::iterator	MutantStack<A, B>::end()
{
	return (this->c.end());
}

#endif
